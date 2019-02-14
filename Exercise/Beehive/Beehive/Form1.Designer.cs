namespace Beehive {
    partial class Form1 {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing) {
            if (disposing && (components != null)) {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent() {
			this.groupBox1 = new System.Windows.Forms.GroupBox();
			this.assignJob = new System.Windows.Forms.Button();
			this.label2 = new System.Windows.Forms.Label();
			this.label1 = new System.Windows.Forms.Label();
			this.shifts = new System.Windows.Forms.NumericUpDown();
			this.workerBeeJob = new System.Windows.Forms.ComboBox();
			this.nextShift = new System.Windows.Forms.Button();
			this.report = new System.Windows.Forms.TextBox();
			this.groupBox1.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.shifts)).BeginInit();
			this.SuspendLayout();
			// 
			// groupBox1
			// 
			this.groupBox1.Controls.Add(this.assignJob);
			this.groupBox1.Controls.Add(this.label2);
			this.groupBox1.Controls.Add(this.label1);
			this.groupBox1.Controls.Add(this.shifts);
			this.groupBox1.Controls.Add(this.workerBeeJob);
			this.groupBox1.Cursor = System.Windows.Forms.Cursors.Arrow;
			this.groupBox1.Location = new System.Drawing.Point(31, 28);
			this.groupBox1.Name = "groupBox1";
			this.groupBox1.Size = new System.Drawing.Size(508, 116);
			this.groupBox1.TabIndex = 0;
			this.groupBox1.TabStop = false;
			this.groupBox1.Text = "Worker Bee Assignments";
			// 
			// assignJob
			// 
			this.assignJob.Location = new System.Drawing.Point(14, 82);
			this.assignJob.Name = "assignJob";
			this.assignJob.Size = new System.Drawing.Size(479, 22);
			this.assignJob.TabIndex = 4;
			this.assignJob.Text = "Assign this job to a bee";
			this.assignJob.UseVisualStyleBackColor = true;
			this.assignJob.Click += new System.EventHandler(this.assignJob_Click);
			// 
			// label2
			// 
			this.label2.AutoSize = true;
			this.label2.Location = new System.Drawing.Point(370, 27);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(36, 12);
			this.label2.TabIndex = 3;
			this.label2.Text = "Shifts";
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(14, 27);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(25, 12);
			this.label1.TabIndex = 2;
			this.label1.Text = "Job";
			// 
			// shifts
			// 
			this.shifts.Location = new System.Drawing.Point(371, 47);
			this.shifts.Name = "shifts";
			this.shifts.Size = new System.Drawing.Size(122, 21);
			this.shifts.TabIndex = 1;
			// 
			// workerBeeJob
			// 
			this.workerBeeJob.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
			this.workerBeeJob.FormattingEnabled = true;
			this.workerBeeJob.Items.AddRange(new object[] {
            "Baby bee tutoring",
            "Egg care",
            "Hive maintenance",
            "Honey manufacturing",
            "Nectar collector",
            "Sting partol"});
			this.workerBeeJob.Location = new System.Drawing.Point(14, 46);
			this.workerBeeJob.Name = "workerBeeJob";
			this.workerBeeJob.Size = new System.Drawing.Size(336, 20);
			this.workerBeeJob.TabIndex = 0;
			// 
			// nextShift
			// 
			this.nextShift.Font = new System.Drawing.Font("굴림", 20F, System.Drawing.FontStyle.Bold);
			this.nextShift.Location = new System.Drawing.Point(562, 28);
			this.nextShift.Name = "nextShift";
			this.nextShift.Size = new System.Drawing.Size(209, 116);
			this.nextShift.TabIndex = 1;
			this.nextShift.Text = "Work the next shift";
			this.nextShift.UseVisualStyleBackColor = true;
			this.nextShift.Click += new System.EventHandler(this.nextShift_Click);
			// 
			// report
			// 
			this.report.Location = new System.Drawing.Point(31, 162);
			this.report.Multiline = true;
			this.report.Name = "report";
			this.report.Size = new System.Drawing.Size(739, 264);
			this.report.TabIndex = 2;
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(800, 450);
			this.Controls.Add(this.report);
			this.Controls.Add(this.nextShift);
			this.Controls.Add(this.groupBox1);
			this.MaximizeBox = false;
			this.MinimizeBox = false;
			this.Name = "Form1";
			this.Text = "Beehive Management System";
			this.groupBox1.ResumeLayout(false);
			this.groupBox1.PerformLayout();
			((System.ComponentModel.ISupportInitialize)(this.shifts)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.ComboBox workerBeeJob;
        private System.Windows.Forms.Button assignJob;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.NumericUpDown shifts;
        private System.Windows.Forms.Button nextShift;
        private System.Windows.Forms.TextBox report;
    }
}

