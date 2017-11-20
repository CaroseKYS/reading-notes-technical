class Person{
	private:
		char *name;
		char sex;
		char pid[20];
		int weight;
		int high;
	
	public:
		Person();
		Person(char *, char s, char *p, int w, int h);
		void change_data(char *, char s, char *p, int w, int h);
		void walking(int k, int v); //以速度v行走k步
		void hearing(char *sentence); //将字符串小写变大写，大写变小写
		void speak(int n); //说出整数number的英文句子
		void writing(); // 在屏幕上画出汉字 "曲"
		void print();//输出人的属性值 
		void out(int a); //翻译小于1000的整数
		virtual ~Person(); 
};
