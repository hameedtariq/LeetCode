class Solution {
public:
    int compareVersion(string a, string b) 
    {
        int n=a.length(), m=b.length(), i=0, j=0;
        while(i<n && j<m)
        {
            long long int p=0, q=0;
            while(i<n && a[i]!='.')
            {
                p=(p*10)+a[i]-'0';
                i++;
            }
            while(j<m && b[j]!='.')
            {
                q=(q*10)+b[j]-'0';
                j++;
            }
            if(p>q)
                return 1;
            else if(q>p)
                return -1;
            i++;
            j++;
        }

        while(i<n)
        {
            long long int p=0;
            while(i<n && a[i]!='.')
            {
                p= (p*10)+ (a[i]-'0');
                i++;
            }
            if(p>0)
                return 1;
            i++;
        }
        while(j<m)
        {
            long long int p=0;
            while(j<m && b[j]!='.')
            {
                p= (p*10)+ (b[j]-'0');
                j++;
            }
            if(p>0)
                return -1;
            j++;
        }
        return 0;
    }
};