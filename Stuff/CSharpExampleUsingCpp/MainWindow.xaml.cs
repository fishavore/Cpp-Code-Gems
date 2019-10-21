using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Runtime.InteropServices;


namespace CSharpExampleUsingCpp
{
    public partial class MainWindow : Window
    {
        const string PATH = "DLLExample.dll";

        //C# to Cpp
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern void GetCSharpText(byte[] str, out System.Int32 strLength);


        [DllImport(PATH, EntryPoint = "GetCppText", CallingConvention = CallingConvention.Cdecl)]
        public static extern void GetCppText(StringBuilder str, ref int strLength);

        //Cpp to C#
        //declare the callback prototype
        delegate int CALLBACK(IntPtr myString, int length);
        //native function to set the callback
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        static extern void SetCallback(CALLBACK callback);

        CALLBACK _callback;


        public MainWindow()
        {
            InitializeComponent();
        }

        private void CppInteropButton_Click(object sender, RoutedEventArgs e)
        {
            int bufferSize = 512;
            StringBuilder buffer = new StringBuilder(bufferSize);
            GetCppText(buffer, ref bufferSize);

            CppInteropButtonTextBox.Text = buffer.ToString();
        }

        private void InteropCppToCSharpButton_Click(object sender, RoutedEventArgs e)
        {
            //Set callback so C++ can call back to C#.
            _callback = Callback;
            SetCallback(_callback);
            //
            System.Int32 size = 256;
            System.Byte[] str = new byte[size];
            for (int i = 0; i < size; i++)
            {
                str[i] = (byte)'1';
            }

            GetCSharpText(str, out size);
            string result = System.Text.Encoding.UTF8.GetString(str, 0, size);
            InteropCppToCSharpButtonTextBox.Text = result;
        }

        // C++ Calls C#.

        /*static*/
        int Callback(IntPtr myString, int length)
        {
            string CSharpString = "This string has been called from C#->Cpp->C#";

            if (CSharpString.Length == 0)
            {
                CSharpString = "GoodBye";
            }

            //make sure the buffer is big enough
            if (CSharpString.Length + 1 > length)
                return 1;

            //convert the managed string into a unmanaged ANSI string
            IntPtr ptr = Marshal.StringToHGlobalAnsi(CSharpString);
            //get the bytes of the unmanaged string
            byte[] bytes = new byte[CSharpString.Length + 1];
            Marshal.Copy(ptr, bytes, 0, CSharpString.Length);
            //copy these bytes into myString
            Marshal.Copy(bytes, 0, myString, bytes.Length);
            //free the unmanaged memory

            Marshal.FreeHGlobal(ptr);
            return 0;
        }
        void SomeFunction()
        {
            //set the callback somewhere in your code
            SetCallback(Callback);
        }
    }
}
