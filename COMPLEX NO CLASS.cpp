#include <iostream>

using namespace std;
class ComplexNumbers
{
    private:
        int real;
        int imag;

    public:
        ComplexNumbers(int r, int i): real(r), imag(i) {};

        ComplexNumbers(): real(0), imag(0) {};


        void plus(const ComplexNumbers& c)
        {
            //ComplexNumbers comp;
            this->real = this->real + c.real;
            this->imag = this->imag + c.imag;
            //return comp;
        }
        void multiply(ComplexNumbers &c)
        {
            //ComplexNumbers comp;
            int e,d;
            e = (this->real*c.real)-(this->imag*c.imag);
            d = (this->real*c.imag)+(this->imag*c.real);
            this->real=e;
            this->imag=d;
        //    return comp;
        }
        void print(void)
        {
            if(this->imag>=0){
            cout << this->real<< " + i" << this->imag  << endl;
            }
            else{
                this->imag=this->imag * (-1);
                 cout << this->real<< " - i" << this->imag  << endl;
            }
        }
};

int main() {
    int real1, imaginary1, real2, imaginary2;

    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;

    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);

    int choice;
    cin >> choice;

    if(choice == 1) {
        c1.plus(c2);
        c1.print();
    }
    else if(choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    else {
        return 0;
    }

}

