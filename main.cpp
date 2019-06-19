#include <stdio.h>
#include <string.h>

#define N 8

class queen
{
   public:
      queen()
      {
         memset(h_, 0, sizeof(h_));
         memset(v_, 0, sizeof(v_));
         memset(s_, 0, sizeof(s_));
         memset(b_, 0, sizeof(b_));
         memset(chessboard, 0, sizeof(chessboard));

         solution(0);
      }

      bool solution(int k)
      {
         if ( k == N )
            return true;

         for ( int i = 0; i < N; i++ )
         {
            if ( place(k, i) ) {
               if ( solution(k + 1) ) {
                  return true;
               } else {
                  clear(k, i);
               }
            }
         }

         return false;
      }

      bool place(int x, int y)
      {
         int s = x - y + N;
         int b = y - x + N;
         int h = y;
         int v = x;

         if ( h_[h] == false && v_[v] == false && s_[s] == false && b_[b] == false )
         {
            chessboard[x][y] = 1;
            h_[h] = true;
            v_[v] = true;
            s_[s] = true;
            b_[b] = true;

            return true;
         }

         return false;
      }

      void clear(int x, int y )
      {
         int s = x - y + N;
         int b = y - x + N;
         int h = y;
         int v = x;

         if ( h_[h] == true && v_[v] == true && s_[s] == true && b_[b] == true )
         {
            chessboard[x][y] = 0;
            h_[h] = false;
            v_[v] = false;
            s_[s] = false;
            b_[b] = false;
         }
         else
         {
            printf("exception!!! clear error!");
         }
      }

      void dump()
      {
         for ( int i = 0; i < N; i++ )
         {
            for ( int j = 0; j < N; j++ )
            {
               printf(j != N - 1 ? "%d, " : "%d\n", chessboard[i][j]);
            }
         }             
      }

   private:
      int chessboard[N][N];
      bool h_[N];
      bool v_[N];
      bool s_[2 * N - 1];
      bool b_[2 * N - 1];
};

int main()
{
   queen q;
   q.dump();
   return 0;
}
