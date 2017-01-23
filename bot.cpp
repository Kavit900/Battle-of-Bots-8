/*
Stay Calm and Cool and keep learning.
*/

#include <bits/stdc++.h>

using namespace std;

int hex_mat[6][7];

int val[6][7];

vector<int> g[50];

map<int, pair<int, int> > map_val_to_points;


vector<int> t1(9,0);
int visited[50];

int moves;

int mkh;

void custom_build_map()
{
  
  // neighbors for 1
  g[1].push_back(2);
  g[1].push_back(8);
  
  // neighbors for 2
  g[2].push_back(1);
  g[2].push_back(8);
  g[2].push_back(9);
  g[2].push_back(10);
  g[2].push_back(3);
  
  // neighbors for 3
  g[3].push_back(2);
  g[3].push_back(4);
  g[3].push_back(10);
  
  // neighbors for 4
  g[4].push_back(3);
  g[4].push_back(10);
  g[4].push_back(11);
  g[4].push_back(12);
  g[4].push_back(5);
  
  // neighbors for 5
  g[5].push_back(4);
  g[5].push_back(12);
  g[5].push_back(6);
  
  // neighbors for 6
  g[6].push_back(5);
  g[6].push_back(12);
  g[6].push_back(13);
  g[6].push_back(14);
  g[6].push_back(7);
  
  // neighbors for 7
  g[7].push_back(6);
  g[7].push_back(14);
    
  // neighbors for 8
  g[8].push_back(1);
  g[8].push_back(2);
  g[8].push_back(9);
  g[8].push_back(15);
  
  // neighbors for 9
  g[9].push_back(2);
  g[9].push_back(8);
  g[9].push_back(15);
  g[9].push_back(16);
  g[9].push_back(17);
  g[9].push_back(10);
  
  // neighbors for 10
  g[10].push_back(2);
  g[10].push_back(3);
  g[10].push_back(4);
  g[10].push_back(9);
  g[10].push_back(11);
  g[10].push_back(17);

  // neighbors for 11  
  g[11].push_back(4);
  g[11].push_back(10);
  g[11].push_back(17);
  g[11].push_back(18);
  g[11].push_back(19);
  g[11].push_back(12);
  
  // neighbors for 12
  g[12].push_back(4);
  g[12].push_back(5);
  g[12].push_back(6);
  g[12].push_back(11);
  g[12].push_back(13);
  g[12].push_back(19);
  
  // neighbors for 13 
  g[13].push_back(6);
  g[13].push_back(12);
  g[13].push_back(14);
  g[13].push_back(19);
  g[13].push_back(20);
  g[13].push_back(21);
  
  // neighbors for 14
  g[14].push_back(6);
  g[14].push_back(7);
  g[14].push_back(13);
  g[14].push_back(21);
  
  // neighbors for 15
  g[15].push_back(8);
  g[15].push_back(9);
  g[15].push_back(16);
  g[15].push_back(22);
  
  // neighbors for 16
  g[16].push_back(9);
  g[16].push_back(15);
  g[16].push_back(17);
  g[16].push_back(22);
  g[16].push_back(23);
  g[16].push_back(24);
  
  // neighbors for 17
  g[17].push_back(9);
  g[17].push_back(10);
  g[17].push_back(11);
  g[17].push_back(16);
  g[17].push_back(18);
  g[17].push_back(24);
  
  // neighbors for 18
  g[18].push_back(11);
  g[18].push_back(17);
  g[18].push_back(19);
  g[18].push_back(24);
  g[18].push_back(25);
  g[18].push_back(26);
  
  // neighbors for 19
  g[19].push_back(11);
  g[19].push_back(12);
  g[19].push_back(13);
  g[19].push_back(18);
  g[19].push_back(20);
  g[19].push_back(26);
  
  // neighbors for 20
  g[20].push_back(13);
  g[20].push_back(19);
  g[20].push_back(21);
  g[20].push_back(26);
  g[20].push_back(27);
  g[20].push_back(28);
  
  // neighbors for 21
  g[21].push_back(13);
  g[21].push_back(14);
  g[21].push_back(20);
  g[21].push_back(28);
  
  // neighbors for 22
  g[22].push_back(15);
  g[22].push_back(16);
  g[22].push_back(23);
  g[22].push_back(29);
  
  // neighbors for 23
  g[23].push_back(16);
  g[23].push_back(22);
  g[23].push_back(24);
  g[23].push_back(29);
  g[23].push_back(30);
  g[23].push_back(31);
  
  // neighbors for 24
  g[24].push_back(16);
  g[24].push_back(17);
  g[24].push_back(18);
  g[24].push_back(23);
  g[24].push_back(31);
  g[25].push_back(26);
  g[25].push_back(31);
  g[25].push_back(32);
  g[25].push_back(33);
  
  // neighbors for 26
  g[26].push_back(18);
  g[26].push_back(19);
  g[26].push_back(20);
  g[26].push_back(25);
  g[26].push_back(27);
  g[26].push_back(33);
  
  // neighbors for 27
  g[27].push_back(20);
  g[27].push_back(26);
  g[27].push_back(28);
  g[27].push_back(33);
  g[27].push_back(34);
  g[27].push_back(35);
  
  // neighbors for 28
  g[28].push_back(20);
  g[28].push_back(21);
  g[28].push_back(27);
  g[28].push_back(35);
  
  // neighbors for 29
  g[29].push_back(22);
  g[29].push_back(23);
  g[29].push_back(30);
  g[29].push_back(36);
  
  // neighbors for 30
  g[30].push_back(23);
  g[30].push_back(29);
  g[30].push_back(31);
  g[30].push_back(36);
  g[30].push_back(37);
  g[30].push_back(38);
  
  // neighbors for 31
  g[31].push_back(23);
  g[31].push_back(24);
  g[31].push_back(25);
  g[31].push_back(30);
  g[31].push_back(32);
  g[31].push_back(38);
  
  // neighbors for 32
  g[32].push_back(25);
  g[32].push_back(31);
  g[32].push_back(33);
  g[32].push_back(38);
  g[32].push_back(39);
  g[32].push_back(40);
  
  // neighbors for 33
  g[33].push_back(25);
  g[33].push_back(26);
  g[33].push_back(27);
  g[33].push_back(32);
  g[33].push_back(34);
  g[33].push_back(40);
  
  // neighbors for 34
  g[34].push_back(27);
  g[34].push_back(33);
  g[34].push_back(35);
  g[34].push_back(40);
  g[34].push_back(41);
  g[34].push_back(42);
  
  // neighbors for 35
  g[35].push_back(27);
  g[35].push_back(28);
  g[35].push_back(34);
  g[35].push_back(42);
  
  // neighbors for 36
  g[36].push_back(29);
  g[36].push_back(30);
  g[36].push_back(37);
  
  // neighbors for 37
  g[37].push_back(30);
  g[37].push_back(36);
  g[37].push_back(38);
  
  // neighbors for 38
  g[38].push_back(30);
  g[38].push_back(31);
  g[38].push_back(32);
  g[38].push_back(37);
  g[38].push_back(39);
  
  // neighbors for 39
  g[39].push_back(32);
  g[39].push_back(38);
  g[39].push_back(40);
  
  // neighbors for 40
  g[40].push_back(32);
  g[40].push_back(33);
  g[40].push_back(34);
  g[40].push_back(39);
  g[40].push_back(41);
  
  // neighbors for 41 
  g[41].push_back(34);
  g[41].push_back(40);
  g[41].push_back(42);
  
  // neighbors for 42
  g[42].push_back(34);
  g[42].push_back(35);
  g[42].push_back(41);
}


int cnt_of_enemy_cells(int s, int enemy)
{
  int cnt = 0;
  for(int i=0; i<g[s].size(); i++)
  {
    pair<int, int> temp  = map_val_to_points[g[s][i]];
    if(hex_mat[temp.first][temp.second]==enemy)
    {
      cnt++;
    }
  }
  return cnt;
}

int cnt_of_our_cells(int s, int enemy)
{
  int cnt = 0;
  for(int i=0; i<g[s].size(); i++)
  {
    pair<int, int> temp  = map_val_to_points[g[s][i]];
    if(hex_mat[temp.first][temp.second]==enemy)
    {
      cnt++;
    }
  }
  return cnt;
}


void dfs(int s, int cnt, int enemy, int xpos, int ypos)
{
  if(cnt>2)
  {
    return;
  }
  if(visited[s]==1)
  {
    return;
  }
  visited[s] = 1;
  pair<int, int> cur_pos = map_val_to_points[s];
  for(int i=0; i<g[s].size(); i++)
  {
    if(visited[g[s][i]]==1)
    {
      continue;
    }
    if(visited[g[s][i]]==0)
    {
      int val = g[s][i];
      pair<int, int> temp = map_val_to_points[val];
      if(hex_mat[temp.first][temp.second]==0 && t1[5]==0)
      {
        t1[0] = xpos;
        t1[1] = ypos;
        t1[2] = temp.first;
        t1[3] = temp.second;
        t1[4] = cnt_of_enemy_cells(g[s][i], enemy);
        t1[5] = 1;
        t1[6] = cnt;
      }
      else if(hex_mat[temp.first][temp.second]==0 && t1[5]==1)
      {
        if(cnt_of_enemy_cells(g[s][i],enemy) > t1[4])
        {
          t1[0] = xpos;
          t1[1] = ypos;
          t1[2] = temp.first;
          t1[3] = temp.second;
          t1[4] = cnt_of_enemy_cells(g[s][i], enemy);
          t1[5] = 1;
          t1[6] = cnt;
        }
      }
      dfs(g[s][i], cnt+1, enemy, xpos, ypos);
      //cout<<"Value of s: "<<s<<endl;
      //cout<<"Value of child of s: "<<g[s][i]<<endl;
      //cout<<"Value of cnt: "<<cnt<<endl;
    }
  }
}

int main()
{
  int cnt = 1;
  for(int i=0; i<50; i++)
  {
    visited[i] = 0;
  }
  for(int i=0; i<6; i++)
  {
    for(int j=0; j<7; j++)
    {
      int x;
      cin>>x;
      hex_mat[i][j] = x;
      val[i][j] = cnt;
      map_val_to_points[cnt] = make_pair(i,j);
      cnt++;
    }
  }
  custom_build_map();
  cin>>moves;
  cin>>mkh;
  vector<pair<int, vector<int> > > final_ans_dfs;
  if(mkh == 1)
  {
    for(int i=0; i<6; i++)
    {
      for(int j=0; j<7; j++)
      {
        if(hex_mat[i][j]==mkh)
        {
          //cout<<"Sending value: "<<val[i][j]<<endl;
          pair<int, int> cur_pos = map_val_to_points[val[i][j]];
          dfs(val[i][j],1,2,cur_pos.first,cur_pos.second);
          t1[8] = i;
          t1[9] = j;
          final_ans_dfs.push_back(make_pair(t1[4], t1));
          //cout<<t1[4]<<endl;
          //cout<<t1.size()<<endl;
          t1.clear();
          t1.resize(6);
          for(int o=0; o<50; o++)
          {
            visited[o] = 0;
          }
        }
      }
    }
    sort(final_ans_dfs.begin(), final_ans_dfs.end());
    pair<int, vector<int> > xx = final_ans_dfs[final_ans_dfs.size()-1];
    //cout<<xx.first<<endl;
    int i_fnl = final_ans_dfs.size()-1;
    if(final_ans_dfs.size()>1)
    {
      pair<int, vector<int> > xxx1 = final_ans_dfs[final_ans_dfs.size()-1];
      vector<int> xxx2 = xxx1.second;
      int cnt1 = cnt_of_our_cells(val[xxx2[7]][xxx2[8]], mkh);
      if(cnt1 >2)
      {
        i_fnl = final_ans_dfs.size()-2;
      }
      xx = final_ans_dfs[i_fnl];
    }
    vector<int> xx1 = xx.second;
    int max1 = xx1[4];
    if(xx1[6]==2)
    {
      int i = i_fnl;
      while(1)
      {
        if(i<0)
        {
          break;
        }
        pair<int, vector<int> > xx2 = final_ans_dfs[i];
        vector<int> xx3 = xx2.second;
        if(xx3[4]>=max1)
        {
          xx1 = xx3;
          break;
        }
      }
    }
    else
    {
      
    }
    //cout<<xx1.size()<<endl;
    cout<<xx1[0]<<" "<<xx1[1]<<endl;
    cout<<xx1[2]<<" "<<xx1[3]<<endl;
    //cout<<"Reached here after dfs"<<endl;
    return 0;
    
  }
  else
  {
    for(int i=0; i<6; i++)
    {
      for(int j=0; j<7; j++)
      {
        if(hex_mat[i][j]==mkh)
        {
          pair<int, int> cur_pos = map_val_to_points[val[i][j]];
          dfs(val[i][j],1,1,cur_pos.first,cur_pos.second);
          final_ans_dfs.push_back(make_pair(t1[4], t1));
          t1.clear();
          t1.resize(6);
          for(int o=0; o<50; o++)
          {
            visited[o] = 0;
          }
        }
      }
    }
    sort(final_ans_dfs.begin(), final_ans_dfs.end());
    pair<int, vector<int> > xx = final_ans_dfs[final_ans_dfs.size()-1];
    int i_fnl = final_ans_dfs.size()-1;
    if(final_ans_dfs.size()>1)
    {
      pair<int, vector<int> > xxx1 = final_ans_dfs[final_ans_dfs.size()-1];
      vector<int> xxx2 = xxx1.second;
      int cnt1 = cnt_of_our_cells(val[xxx2[7]][xxx2[8]], mkh);
      if(cnt1 >2)
      {
        i_fnl = final_ans_dfs.size()-2;
      }
    }
    vector<int> xx1 = xx.second;
    int max1 = xx1[4];
    if(xx1[6]==2)
    {
      int i = i_fnl;
      while(1)
      {
        if(i<0)
        {
          break;
        }
        pair<int, vector<int> > xx2 = final_ans_dfs[i];
        vector<int> xx3 = xx2.second;
        if(xx3[4]>=max1)
        {
          xx1 = xx3;
          break;
        }
      }
    }
    cout<<xx1[0]<<" "<<xx1[1]<<endl;
    cout<<xx1[2]<<" "<<xx1[3]<<endl;
    return 0;
  }
  return 0;
}







