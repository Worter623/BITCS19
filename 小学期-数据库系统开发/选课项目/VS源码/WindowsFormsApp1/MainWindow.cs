using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;


namespace WindowsFormsApp1
{
    public partial class MainWindow : Form
    {
        private string id;
        private SqlWarehouse warehouse = new SqlWarehouse();
        private Fun fun = new Fun();
        private DataTable dtcan = new DataTable();
        private DataTable dtalready = new DataTable();
        public MainWindow()
        {
            InitializeComponent();
            labelcredit.Text = "已选学分：0";
            labelcoursecount.Text = "已选课程数：0";
        }

        private void SetLabel()
        {
            labelcoursecount.Text = "已选课程数：" + dataGridViewAlready.RowCount;
            labelcredit.Text = "已选学分：" + fun.Count(dataGridViewAlready, 1);
        }
        private void ClearAll()
        {
            dataGridViewCan.DataSource = null;
            dataGridViewAlready.DataSource = null;
            labelnotice.Text = "请输入学号";
            SetLabel();
            dataGridViewCan.Columns.Clear();
            dataGridViewCan.Rows.Clear();
            dataGridViewAlready.Columns.Clear();
            dataGridViewAlready.Rows.Clear();

        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (textBox1.Text == "")
            {
                MessageBox.Show("请输入学号");
            }
            else
            {
                try
                {//先检查学号存不存在
                    id = textBox1.Text;
                    object resultSname = warehouse.ExecuteScalarStringSql("select [name] from Student where ID = " + id);
                    if (resultSname == null)
                    {
                        MessageBox.Show("学号不存在或输入错误");
                        ClearAll();
                    }
                    else
                    {//学号存在
                        ClearAll();
                        SqlCommand sqlcan = warehouse.StringtoSqlCommand("execute SelectUntakeLesson " + id);
                        dtcan = warehouse.SelectDataTable(sqlcan);
                        dataGridViewCan.DataSource = dtcan;
                        SqlCommand sqlalready = warehouse.StringtoSqlCommand("execute SelectTakenLesson " + id);
                        dtalready = warehouse.SelectDataTable(sqlalready);
                        dataGridViewAlready.DataSource = dtalready;
                        labelnotice.Text = "你好," + resultSname.ToString() + "！请选择3-5门课 已选课程总学分必须介于8-12";
                        if (dataGridViewCan.ColumnCount == 4)
                            fun.SetDataGridViewStyle("select", dataGridViewCan, "选课", 0);
                        if (dataGridViewAlready.ColumnCount == 4)
                            fun.SetDataGridViewStyle("delete", dataGridViewAlready, "退课", 1);
                        SetLabel();
                    }
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message + "你可能输入了错误的字符。请输入长度为10位的学号。");
                }
                textBox1.Text = "";
            }
        }

        private void dataGridViewCan_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.ColumnIndex == 4)
            {
                fun.MoveRow(dtcan, dtalready, e.RowIndex);
                SetLabel();
            }
        }

        private void dataGridViewAlready_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.ColumnIndex == 4)
            {
                fun.MoveRow(dtalready, dtcan, e.RowIndex);
                SetLabel();
            }
        }

        private void ButtonExit_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void ButtonAdmit_Click(object sender, EventArgs e)
        {
            float count = fun.Count(dataGridViewAlready, 1);
            if (dataGridViewAlready.RowCount < 3 || dataGridViewAlready.RowCount > 5)
                MessageBox.Show("只能选择3-5门课！");
            else if (count < 8 || count > 12)
                MessageBox.Show("已选择课程的总学分必须介于8-12！");
            else
            {
                SqlCommand deletesql = warehouse.StringtoSqlCommand("delete from TakeLesson where StudentID = " + id);
                deletesql.ExecuteNonQuery();
                fun.Admit(dataGridViewAlready, id);
                SetLabel();
                MessageBox.Show("选课成功！");
            }
        }
    }
}
