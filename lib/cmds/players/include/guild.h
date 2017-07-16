

#ifndef l_guild_h
#define l_guild_h


class GuildClass {
    string leader;
    string name;
    string objectName;
    string skill;
}

static void create();
static void init();



int eventInitiate(string str);
void eventJoin(object ob);
int eventRetire(string str);
int eventPromote(string who);
int eventDemote(string who);


#endif /* l_guild_h */


