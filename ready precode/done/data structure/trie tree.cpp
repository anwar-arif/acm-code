
const int N = 10000+5;

struct node
{
    bool is_end;
    int prefix;
    node* child[26];

}*head;

void init()
{
    head = new node();
    head ->is_end = false;
    head ->prefix = 0;
}

void add(string s)
{
    node* cur = head;
    cur -> prefix++;
    int len = SZ(s);
    for(int i = 0 ; i< len;i++){
        int id = s[i] - 'a';
        if(cur->child[id] == NULL){
            cur -> child[id] = new node();
        }
        cur = cur -> child[id];
        cur -> prefix++;
    }
    cur -> is_end = true;
}

bool search(string s)
{
    node* cur = head;
    int len = SZ(s);
    for(int i = 0 ; i < len;i++){
        int id = s[i] - 'a';
        if(cur ->child[id] == NULL){
            return false;
        }
        cur = cur -> child[id];
    }
    return cur->is_end;
}

int cnt_prefix(string s)
{
    node* cur = head;
    int cnt = 0;
    int len = SZ(s);
    for(int i = 0 ; i < len;i++){
        int id = s[i] - 'a';
        if(cur -> child[id] == NULL){
            return 0;
        }
        cur = cur ->child[id];
        //cnt += cur->prefix;
    }
    return cur->prefix;
}

int main()
{
      init();
      for(int i = 1; i<= 5;i++)
      {
          string s;
          cin>>s;
          add(s);
          cin>>s;
          pf("%d\n",cnt_prefix(s));
      }
      return 0;
}
