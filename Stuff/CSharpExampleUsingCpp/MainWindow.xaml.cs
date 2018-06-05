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

        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetValue();

        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static unsafe extern int GetText(byte[] str, int strLength);

        public MainWindow()
        {
            InitializeComponent();

        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            int size = 256;
            System.Byte[] str = new byte[size];
            GetText(str, size);
            string result = System.Text.Encoding.UTF8.GetString(str);
            TextBox.Text = result;
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            int value = GetValue();
            TextBoxGetVal.Text = value.ToString();
        }
    }
}
