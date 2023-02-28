

namespace WindowsFormsApp1
{
    partial class MainWindow
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle11 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle12 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle13 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle14 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle15 = new System.Windows.Forms.DataGridViewCellStyle();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.labelnotice = new System.Windows.Forms.Label();
            this.dataGridViewCan = new System.Windows.Forms.DataGridView();
            this.dataGridViewAlready = new System.Windows.Forms.DataGridView();
            this.labelcredit = new System.Windows.Forms.Label();
            this.labelcoursecount = new System.Windows.Forms.Label();
            this.ButtonAdmit = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.ButtonExit = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewCan)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewAlready)).BeginInit();
            this.SuspendLayout();
            // 
            // textBox1
            // 
            this.textBox1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(113)))), ((int)(((byte)(200)))), ((int)(((byte)(226)))));
            this.textBox1.Font = new System.Drawing.Font("方正吕建德字体", 15F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.textBox1.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(113)))), ((int)(((byte)(57)))), ((int)(((byte)(54)))));
            this.textBox1.Location = new System.Drawing.Point(708, 25);
            this.textBox1.MaximumSize = new System.Drawing.Size(400, 400);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(200, 35);
            this.textBox1.TabIndex = 0;
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.Color.MintCream;
            this.button1.Cursor = System.Windows.Forms.Cursors.Hand;
            this.button1.Font = new System.Drawing.Font("李旭科书法 v1.4", 15F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.button1.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(55)))), ((int)(((byte)(38)))), ((int)(((byte)(95)))));
            this.button1.Location = new System.Drawing.Point(950, 22);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(118, 43);
            this.button1.TabIndex = 1;
            this.button1.Text = "确认";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // labelnotice
            // 
            this.labelnotice.AutoSize = true;
            this.labelnotice.Font = new System.Drawing.Font("方正启体简体", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.labelnotice.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(55)))), ((int)(((byte)(38)))), ((int)(((byte)(95)))));
            this.labelnotice.Location = new System.Drawing.Point(12, 25);
            this.labelnotice.Name = "labelnotice";
            this.labelnotice.Size = new System.Drawing.Size(115, 24);
            this.labelnotice.TabIndex = 2;
            this.labelnotice.Text = "请输入学号";
            this.labelnotice.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // dataGridViewCan
            // 
            this.dataGridViewCan.AllowUserToAddRows = false;
            this.dataGridViewCan.AllowUserToDeleteRows = false;
            this.dataGridViewCan.AllowUserToResizeColumns = false;
            this.dataGridViewCan.AllowUserToResizeRows = false;
            this.dataGridViewCan.BackgroundColor = System.Drawing.SystemColors.Menu;
            dataGridViewCellStyle11.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
            dataGridViewCellStyle11.BackColor = System.Drawing.SystemColors.Control;
            dataGridViewCellStyle11.Font = new System.Drawing.Font("宋体", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            dataGridViewCellStyle11.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(55)))), ((int)(((byte)(38)))), ((int)(((byte)(95)))));
            dataGridViewCellStyle11.SelectionBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(246)))), ((int)(((byte)(210)))), ((int)(((byte)(227)))));
            dataGridViewCellStyle11.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle11.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.dataGridViewCan.ColumnHeadersDefaultCellStyle = dataGridViewCellStyle11;
            this.dataGridViewCan.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewCan.Location = new System.Drawing.Point(12, 71);
            this.dataGridViewCan.Name = "dataGridViewCan";
            this.dataGridViewCan.ReadOnly = true;
            this.dataGridViewCan.RowHeadersWidth = 51;
            dataGridViewCellStyle12.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
            this.dataGridViewCan.RowsDefaultCellStyle = dataGridViewCellStyle12;
            this.dataGridViewCan.RowTemplate.Height = 27;
            this.dataGridViewCan.Size = new System.Drawing.Size(1001, 380);
            this.dataGridViewCan.TabIndex = 3;
            this.dataGridViewCan.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridViewCan_CellContentClick);
            // 
            // dataGridViewAlready
            // 
            this.dataGridViewAlready.AllowUserToAddRows = false;
            this.dataGridViewAlready.AllowUserToDeleteRows = false;
            this.dataGridViewAlready.AllowUserToResizeColumns = false;
            this.dataGridViewAlready.AllowUserToResizeRows = false;
            this.dataGridViewAlready.BackgroundColor = System.Drawing.Color.FromArgb(((int)(((byte)(238)))), ((int)(((byte)(238)))), ((int)(((byte)(238)))));
            dataGridViewCellStyle13.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
            dataGridViewCellStyle13.BackColor = System.Drawing.SystemColors.Control;
            dataGridViewCellStyle13.Font = new System.Drawing.Font("宋体", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            dataGridViewCellStyle13.ForeColor = System.Drawing.SystemColors.WindowText;
            dataGridViewCellStyle13.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle13.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle13.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.dataGridViewAlready.ColumnHeadersDefaultCellStyle = dataGridViewCellStyle13;
            this.dataGridViewAlready.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewAlready.Location = new System.Drawing.Point(68, 465);
            this.dataGridViewAlready.Name = "dataGridViewAlready";
            this.dataGridViewAlready.ReadOnly = true;
            dataGridViewCellStyle14.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
            dataGridViewCellStyle14.BackColor = System.Drawing.SystemColors.Control;
            dataGridViewCellStyle14.Font = new System.Drawing.Font("宋体", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            dataGridViewCellStyle14.ForeColor = System.Drawing.SystemColors.WindowText;
            dataGridViewCellStyle14.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle14.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle14.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.dataGridViewAlready.RowHeadersDefaultCellStyle = dataGridViewCellStyle14;
            this.dataGridViewAlready.RowHeadersWidth = 51;
            dataGridViewCellStyle15.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
            this.dataGridViewAlready.RowsDefaultCellStyle = dataGridViewCellStyle15;
            this.dataGridViewAlready.RowTemplate.Height = 27;
            this.dataGridViewAlready.Size = new System.Drawing.Size(1000, 180);
            this.dataGridViewAlready.TabIndex = 4;
            this.dataGridViewAlready.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridViewAlready_CellContentClick);
            // 
            // labelcredit
            // 
            this.labelcredit.AutoSize = true;
            this.labelcredit.Font = new System.Drawing.Font("方正启体简体", 15F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.labelcredit.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(55)))), ((int)(((byte)(38)))), ((int)(((byte)(95)))));
            this.labelcredit.Location = new System.Drawing.Point(403, 658);
            this.labelcredit.Name = "labelcredit";
            this.labelcredit.Size = new System.Drawing.Size(149, 31);
            this.labelcredit.TabIndex = 5;
            this.labelcredit.Text = "已选学分：";
            this.labelcredit.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // labelcoursecount
            // 
            this.labelcoursecount.AutoSize = true;
            this.labelcoursecount.Font = new System.Drawing.Font("方正启体简体", 15F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.labelcoursecount.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(55)))), ((int)(((byte)(38)))), ((int)(((byte)(95)))));
            this.labelcoursecount.Location = new System.Drawing.Point(47, 657);
            this.labelcoursecount.Name = "labelcoursecount";
            this.labelcoursecount.Size = new System.Drawing.Size(176, 31);
            this.labelcoursecount.TabIndex = 6;
            this.labelcoursecount.Text = "已选课程数：";
            this.labelcoursecount.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // ButtonAdmit
            // 
            this.ButtonAdmit.BackColor = System.Drawing.Color.MintCream;
            this.ButtonAdmit.Cursor = System.Windows.Forms.Cursors.Hand;
            this.ButtonAdmit.Font = new System.Drawing.Font("李旭科书法 v1.4", 15F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.ButtonAdmit.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(55)))), ((int)(((byte)(38)))), ((int)(((byte)(95)))));
            this.ButtonAdmit.Location = new System.Drawing.Point(749, 651);
            this.ButtonAdmit.Name = "ButtonAdmit";
            this.ButtonAdmit.Size = new System.Drawing.Size(159, 43);
            this.ButtonAdmit.TabIndex = 7;
            this.ButtonAdmit.Text = "提交选课";
            this.ButtonAdmit.UseVisualStyleBackColor = false;
            this.ButtonAdmit.Click += new System.EventHandler(this.ButtonAdmit_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("方正舒体", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label1.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(52)))), ((int)(((byte)(177)))), ((int)(((byte)(214)))));
            this.label1.Location = new System.Drawing.Point(1019, 134);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(59, 42);
            this.label1.TabIndex = 8;
            this.label1.Text = "可";
            this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("方正舒体", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label2.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(52)))), ((int)(((byte)(177)))), ((int)(((byte)(214)))));
            this.label2.Location = new System.Drawing.Point(1019, 176);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(59, 42);
            this.label2.TabIndex = 9;
            this.label2.Text = "选";
            this.label2.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("方正舒体", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label3.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(52)))), ((int)(((byte)(177)))), ((int)(((byte)(214)))));
            this.label3.Location = new System.Drawing.Point(1019, 218);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(59, 42);
            this.label3.TabIndex = 10;
            this.label3.Text = "课";
            this.label3.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("方正舒体", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label4.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(52)))), ((int)(((byte)(177)))), ((int)(((byte)(214)))));
            this.label4.Location = new System.Drawing.Point(1019, 260);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(59, 42);
            this.label4.TabIndex = 11;
            this.label4.Text = "程";
            this.label4.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("方正舒体", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label5.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(52)))), ((int)(((byte)(177)))), ((int)(((byte)(214)))));
            this.label5.Location = new System.Drawing.Point(1019, 302);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(59, 42);
            this.label5.TabIndex = 12;
            this.label5.Text = "列";
            this.label5.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("方正舒体", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label6.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(52)))), ((int)(((byte)(177)))), ((int)(((byte)(214)))));
            this.label6.Location = new System.Drawing.Point(1019, 344);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(59, 42);
            this.label6.TabIndex = 13;
            this.label6.Text = "表";
            this.label6.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("方正舒体", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label7.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(52)))), ((int)(((byte)(177)))), ((int)(((byte)(214)))));
            this.label7.Location = new System.Drawing.Point(3, 513);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(59, 42);
            this.label7.TabIndex = 14;
            this.label7.Text = "选";
            this.label7.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Font = new System.Drawing.Font("方正舒体", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label8.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(52)))), ((int)(((byte)(177)))), ((int)(((byte)(214)))));
            this.label8.Location = new System.Drawing.Point(3, 477);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(59, 42);
            this.label8.TabIndex = 15;
            this.label8.Text = "已";
            this.label8.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Font = new System.Drawing.Font("方正舒体", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label9.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(52)))), ((int)(((byte)(177)))), ((int)(((byte)(214)))));
            this.label9.Location = new System.Drawing.Point(3, 555);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(59, 42);
            this.label9.TabIndex = 16;
            this.label9.Text = "课";
            this.label9.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Font = new System.Drawing.Font("方正舒体", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label10.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(52)))), ((int)(((byte)(177)))), ((int)(((byte)(214)))));
            this.label10.Location = new System.Drawing.Point(3, 597);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(59, 42);
            this.label10.TabIndex = 17;
            this.label10.Text = "程";
            this.label10.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // ButtonExit
            // 
            this.ButtonExit.BackColor = System.Drawing.Color.MintCream;
            this.ButtonExit.Cursor = System.Windows.Forms.Cursors.Hand;
            this.ButtonExit.Font = new System.Drawing.Font("李旭科书法 v1.4", 15F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.ButtonExit.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(55)))), ((int)(((byte)(38)))), ((int)(((byte)(95)))));
            this.ButtonExit.Location = new System.Drawing.Point(950, 652);
            this.ButtonExit.Name = "ButtonExit";
            this.ButtonExit.Size = new System.Drawing.Size(118, 43);
            this.ButtonExit.TabIndex = 18;
            this.ButtonExit.Text = "退出";
            this.ButtonExit.UseVisualStyleBackColor = false;
            this.ButtonExit.Click += new System.EventHandler(this.ButtonExit_Click);
            // 
            // MainWindow
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(246)))), ((int)(((byte)(210)))), ((int)(((byte)(227)))));
            this.ClientSize = new System.Drawing.Size(1082, 698);
            this.Controls.Add(this.ButtonExit);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.ButtonAdmit);
            this.Controls.Add(this.labelcoursecount);
            this.Controls.Add(this.labelcredit);
            this.Controls.Add(this.dataGridViewAlready);
            this.Controls.Add(this.dataGridViewCan);
            this.Controls.Add(this.labelnotice);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.textBox1);
            this.Name = "MainWindow";
            this.Text = "学生选课系统";
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewCan)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewAlready)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label labelnotice;
        private System.Windows.Forms.DataGridView dataGridViewCan;
        private System.Windows.Forms.DataGridView dataGridViewAlready;
        private System.Windows.Forms.Label labelcredit;
        private System.Windows.Forms.Label labelcoursecount;
        private System.Windows.Forms.Button ButtonAdmit;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Button ButtonExit;
    }
}

