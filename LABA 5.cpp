//Вариант 27. Завод

#include <iostream>
#include <string>
using namespace std;

int input_int(int min, int max);

class Factory
{
protected:
	string name; 
	int price;
	int kolvo_cehov;       
	double profit;
public:
	Factory() : name("NoName"), kolvo_cehov(0),price(0){}

	Factory(string n, int number, int p) : name(n), kolvo_cehov(number), price(p) {}
	
	virtual ~Factory() {}
	
	virtual void output() = 0;
	virtual double prof() = 0;
	virtual void input() = 0;
};

class prod : public Factory
{
protected:
	int kolvo_prod;   
public:
	prod() : Factory(), kolvo_prod(0) {}
	prod(string n, int number,int p, int t) : Factory(n, number , p), kolvo_prod(t){}
	~prod(){
	}
	void input()
	{
		cout << "Name?" << endl;
		getline(cin, name);
		cout << "Number of workshops?" << endl;
		kolvo_cehov = input_int(0, 100);
		cout << "Price of detail?"<<endl;
		price = input_int(0, 1000);
		cout << "The number of parts produced??" << endl;
		kolvo_prod= input_int(0, 1000);
	}
	void output()
	{
		cout << "Factory: " << name << endl;
		cout << "Number of workshops: " << kolvo_cehov << endl;
		cout << "Price of details: " << price << endl;
		cout << "The number of parts produced: " << kolvo_prod << endl;
	}
	double prof()
	{
		return (kolvo_prod * kolvo_cehov*price)/100;
	}
};

class workers : public Factory
{
protected:
	int kolvo; 

public:
	workers() : Factory(), kolvo(0) {}
	workers(string n, int number, int p, int a) : Factory(n, number, p), kolvo(a) {}
	~workers() {}
	void output()
	{
		cout << "Factory: " << name << endl;
		cout << "Number of workshops: " << kolvo_cehov << endl;
		cout << "Price of details: " << price << endl;
		cout << "Numbers of workers: " << kolvo << endl;
	}
	double prof()
	{
		return  kolvo_cehov * price*20 - kolvo*10;
	}
	void input()
	{
		cout << "Name?" << endl;
		getline(cin, name);
		cout << "How many  workshops?" << endl;
		kolvo_cehov = input_int(0, 100);
		cout << "Price of detail?" << endl;
		price = input_int(0, 1000);
		cout << "How many workers?" << endl;
		kolvo = input_int(0, 1000);
	}
};

class import_prod : public prod
{
protected:
	int quality;    //век, в котором происходят исторические события
public:
	import_prod() : prod(), quality(10) {}
	import_prod(string n, int t, int number, int p, int c) : prod(n, number, p, t), quality(c) {}
	~import_prod() {}
	void output()
	{
		prod::output();
		cout << "Quality: " << quality << endl;
	}
	double prof()
	{
		return kolvo_prod * kolvo_cehov + quality*price;
	}
	void input()
	{
		prod::input();
		cout << "quality from 0 to 10?" << endl;
		quality = input_int(0, 10);
	}
};



int main()
{
	Factory* f[3];
	f[0] = new prod;
	f[1] = new workers;
	f[2] = new import_prod;
	for (int i = 0; i < 3; i++)
	{
		f[i]->input();
	}
	system("cls");

	for (int i = 0; i < 3; i++)
	{
		cout << "------------------Factory " << i << endl;
		f[i]->output();
		cout << "Profit: " << f[i]->prof() << endl;
		
	}
	cout << "\nEnd of program" << endl;
	for (int i = 0; i < 3; i++)
	{
		delete f[i];
	}
	return 0;
}


int input_int(int min, int max)
{
	int i;
	bool fail = true;
	do
	{
		cin >> i;
		if (cin.fail() || i < min || i>max || cin.rdbuf()->in_avail() > 1)
			cout << "Error. Please input again." << endl;
		else
			fail = false;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		rewind(stdin);
	} while (fail);
	return i;
}

double input_double(double min, double max)
{
	double i;
	bool fail = true;
	do
	{
		cin >> i;
		if (cin.fail() || i < min || i>max || cin.rdbuf()->in_avail() > 1)
			cout << "Error. Please input again." << endl;
		else
			fail = false;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		rewind(stdin);
	} while (fail);
	return i;
}
