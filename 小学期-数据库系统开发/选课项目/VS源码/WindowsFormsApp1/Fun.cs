using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data.SqlClient;
using System.Data;
using System.Windows.Forms;
namespace WindowsFormsApp1
{
    class Fun
    {
        SqlWarehouse warehouse = new SqlWarehouse();
        public void SetDataGridViewStyle (string cname,DataGridView dgv, string type, int cnumber)
        {
            dgv.Columns.Add(cname, "");
            dgv.Columns[4].DefaultCellStyle.Alignment = DataGridViewContentAlignment.MiddleCenter;
            dgv.Columns[4].DefaultCellStyle.NullValue = type;
            dgv.Columns[4].DefaultCellStyle.ForeColor = System.Drawing.Color.CadetBlue;
            dgv.Columns[4].DefaultCellStyle.Font = new System.Drawing.Font(dgv.DefaultCellStyle.Font, System.Drawing.FontStyle.Underline);
            dgv.Columns[4].ReadOnly = true;
            if (cnumber == 0)
                dgv.Columns[4].DisplayIndex = 0;
            dgv.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;  
        }

        public void MoveRow (DataTable dtfrom,DataTable dtto,int rowindex)
        {
            dtto.Rows.Add(dtfrom.Rows[rowindex].ItemArray);
            DataRow dr = dtfrom.Rows[rowindex];
            dtfrom.Rows.Remove(dr);            
        }

        public float Count(DataGridView dgv, int column)
        {
            float count = 0;
            foreach (DataGridViewRow dgvr in dgv.Rows)
                count += float.Parse(dgvr.Cells[column].Value.ToString());
            return count;
        }

        public void Admit(DataGridView dgv, string StudentID)
        {
            SqlCommand cmd = new SqlCommand();
            SqlParameter parameter = new SqlParameter("@Student", StudentID);           
            foreach (DataGridViewRow dgvr in dgv.Rows)
            {
                cmd.Parameters.Clear();
                cmd = warehouse.StringtoSqlCommand("insert into TakeLesson values (@Student ,'" + dgvr.Cells[0].Value.ToString() + "');");
                cmd.Parameters.Add(parameter);
                cmd.ExecuteNonQuery();
            }
        }
    }
}
