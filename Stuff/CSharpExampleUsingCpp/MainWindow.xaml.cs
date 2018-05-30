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

        [DllImport(PATH, CallingConvention = CallingConvention.StdCall)]
        public static extern void Init();

        [DllImport(PATH, CallingConvention = CallingConvention.StdCall)]
        public static extern void GetString(System.Byte[] str, int size);

        public MainWindow()
        {
            InitializeComponent();

        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            int size = 256;
            System.Byte[] str = new byte[size];

            Init();

            GetString(str, size);
            string result = System.Text.Encoding.Unicode.GetString(str);
            TextBox.Text = result;
        }
    }
}
