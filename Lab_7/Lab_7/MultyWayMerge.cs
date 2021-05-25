using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Lab_7
{
    public class MultyWayMerge
    {
        public static void FilesMerging(int n, string nameForReader, string nameForWriter)
        {
            StreamReader[] streamReaders = new StreamReader[n];
            for (int i = 0; i < n; i++)
            {
                if (0 != new FileInfo(Directory.GetCurrentDirectory() + nameForReader + i + ".txt").Length)
                    streamReaders[i] = new StreamReader(Directory.GetCurrentDirectory() + nameForReader + i + ".txt");
            }
            StreamWriter[] streamWriters = new StreamWriter[n];
            for (int i = 0; i < n; i++)
            {
                streamWriters[i] = new StreamWriter(Directory.GetCurrentDirectory() + nameForWriter + i + ".txt");
                streamWriters[i].Write("");
            }
            int[] series = new int[n];
            bool[] toRead = new bool[n];
            bool flag = true; ;
            for (int i = 0; i < n; i++)
            {
                toRead[i] = true;
                int firstNumber = ReadingNums(streamReaders[i]);
                if (firstNumber != -1)
                {
                    series[i] = firstNumber;
                }
                else
                {
                    toRead[i] = false;
                }
            }
            while (flag)
            {
                for (int i = 0; i < n; i++)
                {
                    while (true)
                    {
                        int index = Minimal(series, toRead);
                        if (index == -1) break;
                        int minElem = series[index];
                        streamWriters[i].Write(minElem + " ");
                        if (toRead[index])
                        {
                            int nextNumber = ReadingNums(streamReaders[index]);
                            if (nextNumber < series[index])
                            {
                                toRead[index] = false;
                            }
                            if (nextNumber != -1)
                            {
                                series[index] = nextNumber;
                            }
                        }
                    }
                    for (int j = 0; j < n; j++)
                    {
                        if (streamReaders[j] != null && !streamReaders[j].EndOfStream)
                        {
                            toRead[j] = true;
                        }
                    }
                }
                flag = false;
                for (int i = 0; i < n; i++)
                {
                    if (streamReaders[i] != null && !streamReaders[i].EndOfStream)
                    {
                        flag = true;
                        break;
                    }
                }
            }
            for (int i = 0; i < n; i++)
            {
                if (new FileInfo(Directory.GetCurrentDirectory() + nameForWriter + i + ".txt").Length != 0)
                    streamWriters[i].Write(" ");
                streamWriters[i].Close();
                if (streamReaders[i] != null)
                    streamReaders[i].Close();
            }
        }
        static int ReadingNums(StreamReader reader)
        {
            if (reader == null) return -1;
            string number = "";
            while (!reader.EndOfStream)
            {
                char numberChar = (char)reader.Read();
                if (numberChar == ' ') break;
                number += numberChar;
            }
            if (number == "") return -1;
            return int.Parse(number);
        }
        static int Minimal(int[] elems, bool[] toRead)
        {
            int min = Int32.MaxValue;
            int ind = -1;
            for (int i = 0; i < elems.Length; i++)
            {
                if (min > elems[i] && toRead[i])
                {
                    min = elems[i];
                    ind = i;
                }
            }
            return ind;
        }
    }
}
