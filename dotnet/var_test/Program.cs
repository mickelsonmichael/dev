using System;

namespace var_test
{
    class Program
    {
        static void Main(string[] args)
        {
					Int64 max = (Int64)int.MaxValue + 1;

					for (var i = 0; i < max; i++)
					{
						if (i == 0) Console.WriteLine(i.GetType());
					}
        }
    }
}
