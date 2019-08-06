    #include <iostream>

    using namespace std;
    class Triplet{
    public:
        long long int gcd;
        long long int x;
        long long int y;
    };
    Triplet gcdExtendedEuclid(long long int a,long long int b){
        //Base Case
        if(b==0){
            Triplet myAns;
            myAns.gcd = a;
            myAns.x = 1;
            myAns.y = 0;
            return myAns;

        }
        Triplet smallAns = gcdExtendedEuclid(b,a%b);
        //Extended euclid says

        Triplet myAns;
        myAns.gcd = smallAns.gcd;
        myAns.x  = smallAns.y;
        myAns.y = (smallAns.x - ((a/b)*(smallAns.y)));
        return myAns;
    }

    long long int gcd(long long int a,long long int b){

    //Special case for a<b
        if(a<b){
            return gcd(b,a);
        }
        // Base case
        if(b == 0){
            return a;
        }

        // Answer step applying EUCLID'S ALGORITHM
        return gcd(b,a%b);
    }

    long long int modInverse(long long int A,long long int M){
        Triplet ans = gcdExtendedEuclid(A,M);
        return ans.x;
    }



    long long int varsach(long long int a,long long int b,long long int d){
        long long int ans1,ans2,ans;
        long long int g = gcd(a,b);

		if(d%g){
                return 0;
		}

		if(d == 0){
			return 1;
		}
        long long int bmoda=modInverse(b,a);
        long long int dmoda=d%a;
        long long int y1=(bmoda*dmoda)%a;

        double temp=((double)d)/((double)b);
        if(d < y1*b){
            return 0;
		}
        long long int n=(temp-y1)/a;

        return n+1;

    }
    int main()
    {
        long int t;
        cin>>t;
        while(t--){
            long long int a,b,d;
            cin>>a>>b>>d;
            long long int ans=varsach(a,b,d);
            cout<<ans<<endl;
        }
        return 0;
    }
