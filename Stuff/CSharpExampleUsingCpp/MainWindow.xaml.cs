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
        public static extern int GetValue();

        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static unsafe extern int GetText(byte[] str, out System.Int32 strLength);

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

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            System.Int32 size = 256;
            System.Byte[] str = new byte[size];
            for (int i = 0; i < size; i++)
            {
                str[i] = (byte)'1';
            }

            GetText(str, out size);
            string result = System.Text.Encoding.UTF8.GetString(str, 0, size);
            TextBox.Text = result;

        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            _callback = Callback;
            SetCallback(_callback);
            //int value = GetValue();
            //TextBoxGetVal.Text = value.ToString();
        }

        // C++ Calls C#.

        /*static*/
        int Callback(IntPtr myString, int length)
        {
            string user = "Hello";

            if (user.Length == 0)
            {
                user = "GoodBye";
            }

            //make sure the buffer is big enough
            if (user.Length + 1 > length)
                return 1;

            //convert the managed string into a unmanaged ANSI string
            IntPtr ptr = Marshal.StringToHGlobalAnsi(user);
            //get the bytes of the unmanaged string
            byte[] bytes = new byte[user.Length + 1];
            Marshal.Copy(ptr, bytes, 0, user.Length);
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
