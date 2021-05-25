using System;
using System.IO;

namespace Lab_7
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Start");
            FilesProcessing.Segments();
            FilesProcessing.Sort(Directory.GetCurrentDirectory(), @"\res");
            while (true)
            {
                MultyWayMerge.FilesMerging(3, @"\res", @"\new");
                if (new FileInfo(Directory.GetCurrentDirectory() + @"\res" + "1" + ".txt").Length == 0 && new FileInfo(Directory.GetCurrentDirectory() + @"\result" + "2" + ".txt").Length == 0) break;
                MultyWayMerge.FilesMerging(3, @"\new", @"\res");
                if (new FileInfo(Directory.GetCurrentDirectory() + @"\res" + "1" + ".txt").Length == 0 && new FileInfo(Directory.GetCurrentDirectory() + @"\res" + "2" + ".txt").Length == 0) break;
            }
            Console.WriteLine("Finish");
        }
    }
}
