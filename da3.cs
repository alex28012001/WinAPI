using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Day3
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] A = new int[5];
            for(int i = 0;i<5;i++)
            {
                Console.WriteLine("Input "+i+" elements:");
                int value = Convert.ToInt32(Console.ReadLine());
                A[i] = value;
            }
            int composition = 1,sum = 0,min = 0;

            for (int i = 0; i < 5; i++)
            {
                composition *= A[i];
                if (A[i] % 2 == 0)
                    sum += A[i];
                if (A[i] < A.Max())
                    min = A[i];
            }


            int j = 4;
             double[,] B = new double[3, j];
             Random rnd = new Random();
             double max = 0,min2 = max, composition2 = 1,sumstolb = 0;
             for (int i = 0; i < 3; i++)
             {
                 for ( j = 0; j < 4; j++)
                 {
                     B[i,j] = rnd.Next(0, 9);
                    if (B[i, j] > max)
                        max = B[i, j];

                    if (B[i, j] < min2)
                        min2 = B[i, j];

                    composition2 *= B[i, j];
                }
             }
            if (sumstolb % 2 == 0)
                ++sumstolb;
            
          
             




            Console.WriteLine("\n");
            Console.WriteLine(String.Join(" ",A));
            Console.WriteLine("Max: "+A.Max());
            Console.WriteLine("Min: " + min);
            Console.WriteLine("Sum: "+A.Sum());
            Console.WriteLine("Composition: " + composition);
            Console.WriteLine("Sum odd: " + sum);
            Console.WriteLine("\n");

            for (int i = 0; i < 3; i++)
            {
               for (int k = 0; k < 4; k++)
                {
                   if(j%2==0)
                       Console.WriteLine();

                    Console.Write(String.Join(" ", B[i,k]));
                }
            }
            Console.WriteLine();
            

            
            Console.WriteLine("Max: " + max);
            Console.WriteLine("Min: " + min2);
            Console.WriteLine("Composition: " + composition2);
            Console.WriteLine("Sum odd stolbs: " + sumstolb);







            Console.Read();
        }           
    }
}
