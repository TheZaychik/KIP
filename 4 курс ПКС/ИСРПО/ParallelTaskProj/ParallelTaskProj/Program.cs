using System;
using System.Threading.Tasks;
using System.Timers;

namespace ParallelTaskProj
{
    class Program
    {
        static void Main(string[] args)
        {
            int from = 0;
            int to = 5000000;
            int i = 0;
            double[] array = new double[to];
            DateTime dt = DateTime.Now;
            for (i = 0; i < to; i++)
            {
                array[i] = Math.Sqrt(i) * Math.Cos(i);
            }
            Console.WriteLine((DateTime.Now - dt).Milliseconds);
            dt = DateTime.Now;
            Parallel.For(from, to, index =>
            {
                array[index] = Math.Sqrt(index) * Math.Cos(index);
            });
            Console.WriteLine((DateTime.Now - dt).Milliseconds);
        }
    

    }
}