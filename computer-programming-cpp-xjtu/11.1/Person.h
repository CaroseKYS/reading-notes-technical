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
		void walking(int k, int v); //���ٶ�v����k��
		void hearing(char *sentence); //���ַ���Сд���д����д��Сд
		void speak(int n); //˵������number��Ӣ�ľ���
		void writing(); // ����Ļ�ϻ������� "��"
		void print();//����˵�����ֵ 
		void out(int a); //����С��1000������
		virtual ~Person(); 
};
