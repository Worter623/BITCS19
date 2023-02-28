using System;
using System.Data.SqlClient;
using System.Data;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    static class ProgramRun
    {
        /// <summary>
        /// 应用程序的主入口点。
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            SqlConnection conn = new SqlConnection();
            conn.ConnectionString = "server=LAPTOP-7O733H1T\\BITPC;database=LessonChoice;uid=sa;pwd=supreme,";
            conn.Open();
            if (conn.State == ConnectionState.Open)
            {//先检测连接成不成
                MessageBox.Show("欢迎来到学生选课系统，请先输入学号");
                Application.Run(new MainWindow());
                conn.Close();
            }
            else
                MessageBox.Show("出bug了！你可能连不上数据库欸");

        }
    }
}
