using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpExampleUsingCpp
{
    public class CppToCS
    {
        public static string InsideCS(string text, string moreText)
        {
            string uselessMessage = text;
            string moreUselessMessage = moreText;

            Console.WriteLine(uselessMessage);
            Console.WriteLine(moreUselessMessage);

            return "And back to Cpp";
        }
    }
}
