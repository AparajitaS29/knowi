#include<iostream>
#include<iomanip>
using std::cout;


int intial_mis = 3, intial_cani = 3, I;
int  final_mis = 0, final_cani = 0;
int  position = 0, pts = 0, pick = 0;

void print(char cm1, char cm2)
{
    cout << "\n\n\n";
    for (int i = 0; i < final_mis; i++)
        cout << " $ "; /*here $ represent missionaries on other bank*/
    for (int i = 0; i < final_cani; i++)
        cout << " @ ";/*here @ represent cannibals on other bank*/

    if (pts == 0)
        cout << "     ~~~~~~~~~~(" << cm1 << "," << cm2 << ")  ";
    else
        cout << "     (" << cm1 << "," << cm2 << ")~~~~~~~~~~  ";
    for (int i = 0; i < intial_mis; i++)
        cout << " $ ";
    for (int i = 0; i < intial_cani; i++)
        cout << " @ ";
}

int safe()
{
    return (final_cani == 3 && final_mis == 3) ? 0 : 1;
}

void ans()
{
    while (safe())
    {
        if (!pts)
        {
            switch (pick)
            {
                case 1: print('@', ' ');
                        intial_cani++;
                        break;
                case 2: print('@', '$');
                        intial_cani++; intial_mis++;
                        break;
            }

            if (((intial_mis - 2) >= intial_cani && (final_mis + 2) >= final_cani) || (intial_mis - 2) == 0)
            {
                intial_mis = intial_mis - 2;
                pick = 1;
                print('$', '$');
                pts = 1;
            }
            else if ((intial_cani - 2) < intial_mis && (final_mis == 0 || (final_cani + 2) <= final_mis) || intial_mis == 0)
            {
                intial_cani = intial_cani - 2;
                pick = 2;
                print('@', '@');
                pts = 1;
            }

            else if ((intial_cani--) <= (intial_mis--) && (final_mis++) >= (final_cani++))
            {
                intial_cani = intial_cani - 1;
                intial_mis = intial_mis - 1;
                pick = 3;
                print('$', '@');
                pts = 1;
            }
        }

        else
        {
            switch (pick)
            {
                case 1: print('$', '$');
                        final_mis = final_mis + 2;
                        break;

                case 2: print('@', '@');
                        final_cani = final_cani + 2;
                        break;

                case 3: print('$', '@');
                        final_cani = final_cani + 1;
                        final_mis = final_mis + 1;
                        break;
            }

            if (safe())
            {
                if (((final_cani > 1 && final_mis == 0) || intial_mis == 0))
                {
                    final_cani--;
                    pick = 1;
                    print('@', ' ');
                    pts = 0;
                }

                else if ((intial_cani + 2) > intial_mis)
                {
                    final_cani--; final_mis--;
                    pick = 2;
                    print('@', '$');
                    pts = 0;
                }
            }
        }
    }
}


int main()
{
    cout << "MISSIONARIES AND CANNIBAL ANSWER"<<"\n@-CANNIBLAS \n$-MISSIONARIES";
    print(' ', ' ');
    ans();
    print(' ', ' ');
    return 0;
}

/* HERE I HAVE PASTED THE OUTPUT I GOT IN MY COMPLIER SCREEN;-
MISSIONARIES AND CANNIBAL ANSWER
@-CANNIBLAS
$-MISSIONARIES


     ~~~~~~~~~~( , )   $  $  $  @  @  @


     ~~~~~~~~~~(@,@)   $  $  $  @


     (@,@)~~~~~~~~~~   $  $  $  @


 @      (@, )~~~~~~~~~~   $  $  $  @


 @      ~~~~~~~~~~(@, )   $  $  $  @


 @      ~~~~~~~~~~(@,@)   $  $  $


 @      (@,@)~~~~~~~~~~   $  $  $


 @  @      (@, )~~~~~~~~~~   $  $  $


 @  @      ~~~~~~~~~~(@, )   $  $  $


 @  @      ~~~~~~~~~~($,$)   $  @


 @  @      ($,$)~~~~~~~~~~   $  @


 $  @      (@,$)~~~~~~~~~~   $  @


 $  @      ~~~~~~~~~~(@,$)   $  @


 $  @      ~~~~~~~~~~($,$)   @  @


 $  @      ($,$)~~~~~~~~~~   @  @


 $  $  $      (@, )~~~~~~~~~~   @  @


 $  $  $      ~~~~~~~~~~(@, )   @  @


 $  $  $      ~~~~~~~~~~(@,@)   @


 $  $  $      (@,@)~~~~~~~~~~   @


 $  $  $  @      (@, )~~~~~~~~~~   @


 $  $  $  @      ~~~~~~~~~~(@, )   @


 $  $  $  @      ~~~~~~~~~~(@,@)


 $  $  $  @      (@,@)~~~~~~~~~~


 $  $  $  @  @  @      ( , )~~~~~~~~~~
Process returned 0 (0x0)   execution time : 0.109 s
Press any key to continue.
*/
