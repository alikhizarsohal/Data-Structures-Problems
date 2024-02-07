#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/imgcodecs.hpp>
#include <iostream>
using namespace cv;
using namespace std;
void display_new_image(float** image_array, int rows, int cols, Mat image, string c)
{
    Mat mAtrix_imAge = imread(c);
    for (int m = 0; m < mAtrix_imAge.rows; m++)
    {
        for (int n = 0; n < mAtrix_imAge.cols; n++)
        {
            mAtrix_imAge.at<Vec3b>(m, n)[2] = image_array[m][n];
            mAtrix_imAge.at<Vec3b>(m, n)[1] = image_array[m][n];
            mAtrix_imAge.at<Vec3b>(m, n)[0] = image_array[m][n];
        }
    }
    imshow("...........", image);
    imshow("our_imAge", mAtrix_imAge);
    waitKey(0);
}
void labelling(float** Arr, int r, int c, float New, float old)
{
    for (int i = 0; i <= r; i++)
    {
        for (int j = 0; j <= c; j++)
        {
            if (Arr[i][j] == old)
            {
                Arr[i][j] = New;
            }
        }
    }
}
struct pixel_kA_node{
    int pixel_kA_data;
    pixel_kA_node* next_pixel;
};
class imAge_ki_linkedlist {
private:
    pixel_kA_node* pixel_kA_heAd;
public:
    imAge_ki_linkedlist()
    {
        pixel_kA_heAd = NULL;
    }
    void insert_the_pixel(int pixel)
    {
        pixel_kA_node* temp = new pixel_kA_node;
    temp->pixel_kA_data = pixel;
    temp->next_pixel = NULL;
    if (pixel_kA_heAd == NULL)
    {
        pixel_kA_heAd = temp;
    }
    else
    {
        pixel_kA_node* p = pixel_kA_heAd;
        p = pixel_kA_heAd;
        while (p->next_pixel != NULL)
        {
            p = p->next_pixel;
        }
        p->next_pixel = temp;
    }
    temp = NULL;
    delete temp;
    }
    void display_the_pixels()
    {
        if (pixel_kA_heAd == NULL)
        {
            cout << "List is empty\n";
        }
        else
        {
            int count = 0;
            pixel_kA_node* p = pixel_kA_heAd;
            while (p != NULL)
            {
                cout << p->pixel_kA_data << " ";
                if (p->pixel_kA_data == -1)
                {
                    cout << "\n";
                }
                p = p->next_pixel;
            }
        }
    }
};
struct nodemAx {
    int d;
    nodemAx* n;
};
class link {
private:
    nodemAx* h;
public:
    link()
    {
        h = NULL;
    }
    void Add(int d)
    {
        nodemAx* t = new nodemAx;
        t->d = d;
        t->n = NULL;
        if (h == NULL)
        {
            h = t;
        }
        else
        {
            t->n = h;
            h = t;
        }
        t = NULL;
        delete t;
    }
    int return_at_index(int idx)
    {
        nodemAx* find = h;
        int count = 0;
        while (find != NULL&&count!=idx)
        {
            ++count;
            find = find->n;
        }
        return find->d;
    }
};
class Assignment_1 {
    string pAth_of_imAge;
    string pAth_of_imAge_ground;
    string pAth_of_imAge_originAl;
public:
    Assignment_1(string str)
    {
        this->pAth_of_imAge = str;
    }
    void setground(string str)
    {
        this->pAth_of_imAge_ground = str;
    }
    void setoriginAl(string str)
    {
        this->pAth_of_imAge_originAl = str;
    }
    void tAsk_3(float** Arr, int ir, int ic, Mat mgA)
    {
        string gtr = this->pAth_of_imAge_ground;
        Mat gimage = imread(gtr);
        Mat gim;
        gimage.convertTo(gim, CV_32F);
        float** dA = new float* [gimage.rows];
        for (int i = 0; i < gimage.rows; i++)
        {
            dA[i] = new float[gimage.cols];
        }
        for (int i = 0; i < gimage.rows; i++)
        {
            for (int j = 0; j < gimage.cols; j++) {
                dA[i][j] = gimage.at<Vec3b>(i, j)[0];
            }
        }
        float not_p = 0, fAlse_p = 0, true_p = 0;
        for (int i = 0; i < gimage.rows; i++)
        {
            for (int j = 0; j < gimage.cols; j++)
            {
                if (Arr[i][j] == 255 && dA[i][j] == 255)
                {
                    ++true_p;
                }
                else if (Arr[i][j] == 255 && dA[i][j] == 0)
                {
                    ++fAlse_p;
                }
                else if (Arr[i][j] == 0 && dA[i][j] == 255)
                {
                    ++not_p;
                }
            }
        }
        cout << "\n\n";
        cout << "Dice Coefficient = " << (2 * true_p) / (not_p + (2 * true_p) + fAlse_p) ;
        cout << "\n\n";
    }
    void ArrAy_for_tAsk_1(float**Arr,int ir,int ic,Mat mgA,int ch)
    {
        for (int i = 0; i < ir; i++)
        {
            for (int j = 0; j < ic; j++)
            {
                if (Arr[i][j] == 255)
                    Arr[i][j] = 1;
            }
        }
        for (int i = 0; i < ir; i++)
        {
            for (int j = 0; j < ic; j++)
            {
                if (Arr[i][j] == 255)
                    Arr[i][j] = 1;
            }
        }
        int count = 1;
        int a = -1, b = -1, c = -1, d = -1;
        bool f1 = 0, f2 = 0, f3 = 0, f4 = 0;
        int co = ic, ro = ir;
        for (int i = 0; i < ir; i++)
        {
            for (int j = 0; j < ic; j++)
            {
                if (Arr[i][j] >= 1)
                {
                    a = -1, b = -1, c = -1, d = -1;
                    f1 = 0, f2 = 0, f3 = 0, f4 = 0;
                    if ((j - 1) >= 0 && (j - 1) < co)
                    {
                        a = Arr[i][j - 1];
                    }
                    if ((i - 1) >= 0 && (i - 1) < ro && (j - 1) >= 0 && (j - 1) < co)
                    {
                        b = Arr[i - 1][j - 1];
                    }
                    if ((i - 1) >= 0 && (i - 1) < ro)
                    {
                        c = Arr[i - 1][j];
                    }
                    if ((i - 1) >= 0 && (i - 1) < ro && (j + 1) >= 0 && (j + 1) < co)
                    {
                        d = Arr[i - 1][j + 1];
                    }
                    if (a > 0)
                    {
                        f1 = 1;
                    }
                    if (b > 0)
                    {
                        f2 = 1;
                    }
                    if (c > 0)
                    {
                        f3 = 1;
                    }
                    if (d > 0)
                    {
                        f4 = 1;
                    }
                    if (!f1 && !f2 && !f3 && !f4)
                    {
                        Arr[i][j] = count;
                        count++;
                    }
                    // eqvivalency one neighbour
                    if (f1 && !f2 && !f3 && !f4)//a
                    {
                        labelling(Arr, i, j, Arr[i][j - 1], Arr[i][j]);
                        Arr[i][j] = Arr[i][j - 1];
                    }
                    if (!f1 && f2 && !f3 && !f4)//b
                    {
                        labelling(Arr, i, j, Arr[i - 1][j - 1], Arr[i][j]);
                        Arr[i][j] = Arr[i - 1][j - 1];

                    }
                    if (!f1 && !f2 && f3 && !f4)//c
                    {
                        labelling(Arr, i, j, Arr[i - 1][j], Arr[i][j]);
                        Arr[i][j] = Arr[i - 1][j];

                    }
                    if (!f1 && !f2 && !f3 && f4)//d
                    {
                        labelling(Arr, i, j, Arr[i - 1][j + 1], Arr[i][j]);
                        Arr[i][j] = Arr[i - 1][j + 1];

                    }
                    // eqvivalency two neighbours
                    if (f1 && f2 && !f3 && !f4)//ab ,cd
                    {
                        labelling(Arr, i, j, Arr[i - 1][j - 1], Arr[i][j - 1]);
                        Arr[i][j] = Arr[i][j - 1];
                        //  eqvivalent(v, b);
                    }
                    if (f1 && f4 && !f2 && !f3)//ad ,bc
                    {
                        labelling(Arr, i, j, Arr[i - 1][j + 1], Arr[i][j - 1]);
                        Arr[i][j] = Arr[i][j - 1];
                        //  eqvivalent(v, c);
                    }
                    if (f1 && f3 && !f2 && !f4)//ac ,bd
                    {
                        labelling(Arr, i, j, Arr[i - 1][j], Arr[i][j - 1]);
                        Arr[i][j] = Arr[i][j - 1];
                        // eqvivalent(v, d);
                    }
                    if (f2 && f3 && !f1 && !f4)//bc ,ad
                    {
                        labelling(Arr, i, j, Arr[i - 1][j - 1], Arr[i - 1][j]);
                        Arr[i][j] = Arr[i - 1][j - 1];
                        // eqvivalent(v, c);
                    }
                    if (f3 && f4 && !f1 && !f2)//cd,ab
                    {
                        labelling(Arr, i, j, Arr[i - 1][j], Arr[i - 1][j + 1]);
                        Arr[i][j] = Arr[i - 1][j];
                        // eqvivalent(v, c);
                    }
                    if (f2 && f4 && !f1 && !f3)//bd ,ac
                    {
                        labelling(Arr, i, j, Arr[i - 1][j - 1], Arr[i - 1][j + 1]);
                        Arr[i][j] = Arr[i - 1][j - 1];
                        // eqvivalent(v, c);
                    }
                    // eqvivalency three neighbours
                    if (f1 && f2 && f3 && !f4)//abc,d
                    {
                        labelling(Arr, i, j, Arr[i - 1][j - 1], Arr[i][j - 1]);
                        labelling(Arr, i, j, Arr[i - 1][j - 1], Arr[i - 1][j]);
                        Arr[i][j] = Arr[i - 1][j];
                    }
                    if (f1 && f2 && !f3 && f4)//abd,c
                    {
                        labelling(Arr, i, j, Arr[i - 1][j - 1], Arr[i][j - 1]);
                        labelling(Arr, i, j, Arr[i - 1][j - 1], Arr[i - 1][j + 1]);
                        Arr[i][j] = Arr[i][j - 1];
                    }
                    if (!f1 && f2 && f3 && f4)//bcd,a
                    {
                        labelling(Arr, i, j, Arr[i - 1][j - 1], Arr[i - 1][j]);
                        labelling(Arr, i, j, Arr[i - 1][j], Arr[i - 1][j + 1]);
                        Arr[i][j] = Arr[i - 1][j];
                    }
                }
            }
        }
        float* arr = new float[ir * ic];
        for (int i = 0; i < (ir * ic); i++)
        {
            arr[i] = 0;
        }
        for (int i = 0; i < ir; i++)
        {
            for (int j = 0; j < ic; j++)
            {
                int a;
                if (Arr[i][j] != 0)
                {
                    a = Arr[i][j];
                    ++(arr[a]);
                }
            }
        }
        link mAxstore;
        int A = 0;
        for (int i = 0; i < (ir * ic); i++)
        {
            if (arr[i] >= 500)
            {
                ++A;
                mAxstore.Add(i);
            }
        }
        for (int k = 0; k < A; k++)
        {
            for (int i = 0; i < ir; i++)
            {
                for (int j = 0; j < ic; j++)
                {
                    if (mAxstore.return_at_index(k) == Arr[i][j])
                    {
                        Arr[i][j] = -1;
                    }
                }
            }
        }
        for (int i = 0; i < ir; i++)
        {
            for (int j = 0; j < ic; j++)
            {
                if (Arr[i][j] != -1 && Arr[i][j] != 0)
                {
                    Arr[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < ir; i++)
        {
            for (int j = 0; j < ic; j++)
            {
                if (Arr[i][j] == -1)
                {
                    Arr[i][j] = 255;
                }
            }
        }
        tAsk_3(Arr, ir, ic, mgA);
        if(ch==1)
        display_new_image(Arr, ir, ic, mgA,this->pAth_of_imAge);
        else
        display_new_image(Arr, ir, ic, mgA, this->pAth_of_imAge_originAl);
    }
    void ArrAy_for_tAsk_2_(float** A1,int ir,int ic,Mat mgA)
    {
        float** Arr = new float* [ir];
        for (int i = 0; i < ir; i++)
        {
            Arr[i] = new float[ic];
        }
        srand(time(0));
        int a1 = 0, a2 = 0;
        a1 = rand() % (100) + 1;
        a2 = rand() % (500 - 100) + 1;
        int aa = 0, bb = 0;
        int c1 = 0, c2 = 0;
        int num1 = 0, num2 = 0;
        int p1 = 0, p2 = 0;
        do
        {
            c1 = 0, c2 = 0, num1 = 0, num2 = 0;
            for (int i = 0; i < ir; i++)
            {
                for (int j = 0; j < ic; j++)
                {
                    p1 = a1, p2 = a2;
                    aa = abs(a1 - A1[i][j]);
                    bb = abs(a2 - A1[i][j]);
                    if (aa < bb)
                    {
                        Arr[i][j] = 0;
                    }
                    else
                    {
                        Arr[i][j] = 1;
                    }
                }
            }
            for (int i = 0; i < ir; i++)
            {
                for (int j = 0; j <ic; j++)
                {
                    if (Arr[i][j] == 0)
                    {
                        num1 += A1[i][j];
                        ++c1;
                    }
                    else if (Arr[i][j] == 1)
                    {
                        num2 += A1[i][j];
                        ++c2;
                    }
                }
            }
            a1 = num1 / c1;
            a2 = num2 / c2;
            if (a1 == p1 && a2 == p2)
            {
                break;
            }
        } while ((a1 != p1) || (a2 != p2));
        if (a1 < a2)
        {
            for (int i = 0; i < ir; i++)
            {
                for (int j = 0; j <ic; j++)
                {
                    if (Arr[i][j] == 0)
                    {
                        Arr[i][j] = 255;
                    }
                    else
                    {
                        Arr[i][j] = 0;
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < ir; i++)
            {
                for (int j = 0; j < ic; j++)
                {
                    if (Arr[i][j] == 1)
                    {
                        Arr[i][j] = 255;
                    }
                    else
                    {
                        Arr[i][j] = 0;
                    }
                }
            }
        }
        for (int i = 0; i < ir; i++)
        {
            for (int j = 0; j <ic; j++)
            {
                if (Arr[i][j] == 255)
                    Arr[i][j] = 1;
            }
        }
        ArrAy_for_tAsk_1(Arr, ir, ic, mgA,2);
    }
    void ArrAy_for_tAsk_4(float** fA,int fr,int fc)
    {
        imAge_ki_linkedlist imAge_Array_linkedlist;
        imAge_Array_linkedlist.insert_the_pixel(fr);
        imAge_Array_linkedlist.insert_the_pixel(fc);
        bool f1 = 0, f2 = 0;
        for (int i = 0; i < fr; i++)
        {
            f1 = 0;
            for (int j = 0; j < fc; j++)
            {
                if (fA[i][j] == 255 && f1 == 0)
                {
                    imAge_Array_linkedlist.insert_the_pixel(j);
                    f1 = 1;
                }
                else if (fA[i][j - 1] == 255 && fA[i][j] != 255 && f1 == 1)
                {
                    imAge_Array_linkedlist.insert_the_pixel(j - 1);
                    f1 = 0;
                }
            }
            imAge_Array_linkedlist.insert_the_pixel(-1);
        }
        imAge_Array_linkedlist.display_the_pixels();
    }
    void tAsk_1()
    {
        Mat segmented = imread(this->pAth_of_imAge);
        Mat i210514;
        segmented.convertTo(i210514, CV_32F);
        int counter = 0;
        float** Arr = new float* [segmented.rows];
        for (int i = 0; i < segmented.rows; i++)
        {
            Arr[i] = new float[segmented.cols];
        }
        for (int i = 0; i < segmented.rows; i++)
        {
            for (int j = 0; j < segmented.cols; j++) {
                Arr[i][j] = segmented.at<Vec3b>(i, j)[0];
            }
        }
        ArrAy_for_tAsk_1(Arr, segmented.rows, segmented.cols,segmented,1);
    }
    void tAsk_2()
    {
        Mat segmented = imread(this->pAth_of_imAge_originAl);
        Mat i210514;
        segmented.convertTo(i210514, CV_32F);
        int counter = 0;
        float** Arr = new float* [segmented.rows];
        for (int i = 0; i < segmented.rows; i++)
        {
            Arr[i] = new float[segmented.cols];
        }
        for (int i = 0; i < segmented.rows; i++)
        {
            for (int j = 0; j < segmented.cols; j++) {
                Arr[i][j] = segmented.at<Vec3b>(i, j)[0];
            }
        }
        ArrAy_for_tAsk_2_(Arr, segmented.rows, segmented.cols,segmented);
    }
    void tAsk_4()
    {
        Mat segmented = imread(this->pAth_of_imAge);
        Mat i210514;
        segmented.convertTo(i210514, CV_32F);
        int counter = 0;
        float** Arr = new float* [segmented.rows];
        for (int i = 0; i < segmented.rows; i++)
        {
            Arr[i] = new float[segmented.cols];
        }
        for (int i = 0; i < segmented.rows; i++)
        {
            for (int j = 0; j < segmented.cols; j++) {
                Arr[i][j] = segmented.at<Vec3b>(i, j)[0];
            }
        }
        ArrAy_for_tAsk_4(Arr, segmented.rows, segmented.cols);
    }
};
int main()
{
    string str = "C:/Users/Ali/Pictures/Assignment_ds1/Segmented Outputs/mIMD015.bmp";
    Assignment_1 Assign(str);
    Assign.setoriginAl("C:/Users/Ali/Pictures/Assignment_ds1/Original Images/IMD015.bmp");
    Assign.setground("C:/Users/Ali/Pictures/Assignment_ds1/Ground Truths/IMD015_lesion.bmp");
    /*
    * ****************************************************************************************************************************************************
    *          i have made a class named Assignment and then make separate functions for each task 
    *          so uncomment the following tasks and run them one by one (tAsk#1 is already uncommented)
    */
    Assign.tAsk_1();
//   Assign.tAsk_2();
//   Assign.tAsk_4();
   
    return 0;
}
