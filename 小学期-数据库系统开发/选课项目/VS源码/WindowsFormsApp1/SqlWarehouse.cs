using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data.SqlClient;
using System.Data;

namespace WindowsFormsApp1
{
    class SqlWarehouse
    {
        public SqlCommand StringtoSqlCommand(string words)
        {
            SqlConnection conn = new SqlConnection();
            conn.ConnectionString = "server=LAPTOP-7O733H1T\\BITPC;database=LessonChoice;uid=sa;pwd=supreme,";
            conn.Open();
            SqlCommand command = new SqlCommand();
            command.Connection = conn;
            command.CommandText = words;
            command.CommandType = CommandType.Text;
            return command;
        }
        public DataTable SelectDataTable(SqlCommand command)
        { 
            SqlDataAdapter sda = new SqlDataAdapter(command);
            DataTable dt = new DataTable();
            sda.Fill(dt);
            return dt;
        }
        public object ExecuteScalarStringSql(string words)
        {
            SqlCommand command = StringtoSqlCommand(words);
            object result = command.ExecuteScalar();
            return result;
        }

    }
}
