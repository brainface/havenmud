/*    /cmd *    from Foundation II
 *    a listing of users for creators and ambassadors
 *    created by Descartes of Borg 940724
 */

#include <lib.h>
#include <localtime.h>
#include <config.h>
#include <dirs.h>
#include <daemons.h>

inherit LIB_DAEMON;

static private int *__SortFlags;

static private string query_time();
private string calculateFormatString(int screenSize);

int cmd(string str) {
    object *who, *display;
    string *args;
    string msg, tmp1, tmp2;
    int i, maxi, aflag, bflag, cflag, eflag, gflag, hflag, lflag, mflag;
    int nflag, pflag, rflag, sflag, uflag;
    int screenSize;
    string formatString;
    string bar;

    if (angelp(this_player())) {
         this_player()->eventPrint("You don't count as people yet.");
         return 1;
         }
    if(!str || str == "" || strlen(str) == 1 || str[0] != '-') args = ({});
    else args = explode(str[1..strlen(str)-1], "");
    i = sizeof(args);
    who = filter(users(), "filter_invis", this_object());
    display = who;
    maxi = sizeof(display=sort_array(display,"general_sort",this_object()));
    __SortFlags = ({ eflag, gflag, lflag, rflag, sflag });

    screenSize = ((int*)this_player()->GetScreen())[0];
    formatString = calculateFormatString(screenSize);
    // 74 '-'s.
    bar = "--------------------------------------------------------------------------";
    for(i = 75; i < screenSize; i++) bar += "-";
    bar += "\n";
    msg = bar;
    tmp1 = " " + maxi + ((maxi != 1) ? " people" : " person") + " in current sort ";
    tmp2 = query_time() + " ";
    i = sizeof(tmp1) + sizeof(tmp2);
    msg += tmp1;
    for(i = sizeof(tmp1) + sizeof(tmp2) + 1; i < screenSize; i++) msg += " ";
    msg += tmp2 + "\n";
    msg += bar;
    msg += implode(map_array(display, "map_info", this_object(), formatString), "\n") + "\n";
    msg += bar;
    msg += center(mud_name() + " last rebooted " + ctime(time() - uptime()), screenSize -1);
    message("system", msg, this_player());
    return 1;
}

static int filter_invis(object ob) {
  if (!((int)ob->GetKeyName())) return 0;
  if (rank(this_player()) < ob->GetInvis()) return 0;
  return 1;
}

static int general_sort(object alpha, object beta) {
  int x = rank(beta) - rank(alpha);
  if (x) return x;
  if (playerp(alpha))
  {
    x = beta->GetLevel() - alpha->GetLevel();
    if (x) return x;
  }
  return strcmp(alpha->GetCapName(), beta->GetCapName());
}

private string calculateFormatString(int screenSize) {
  int nomSize = (((screenSize - 21) * 12) / 54);
  int ipSize = (((screenSize - 21) * 18) / 54);
  int envSize = (((screenSize - 21) * 23) / 54);

  if(nomSize < 12) nomSize = 12;
  if(ipSize < 18) ipSize = 18;
  if(envSize < 23) envSize = 23;
  
  return "%:-6s %:4s %:-" + (nomSize-1) + "s %:-" + ipSize + "s %:-6s %:-3s %:-" + envSize + "s";
}

static string map_info(object ob, string formatString) {
    string age, nom, blk, lev, ip, env, idle;
    int* x;
    int tmp;

    x = time_units( (int)ob->GetAge(), 1);
    if(x[1]) age = sprintf("%:-4d D", x[1]);
    else if(x[2]) age = sprintf("%:-4d h", x[2]);
    else age = sprintf("%:-4d m", x[3]);
    nom = (string)ob->GetCapName();
    if((int)ob->GetInvis()) nom = "("+nom+")";
    if(in_edit(ob) || in_input(ob)) nom = "["+nom+"]";
    if((int)ob->GetBlocked("all")) blk = "ALL";
    if((int)ob->GetBlocked("imm")) blk = " I";
      else blk = "  ";
    if((int)ob->GetBlocked("ooc")) blk += "O";
       else blk += " ";
    if (!blk) blk = "   ";    
   if(!(tmp = (int)ob->GetLevel())) lev = "-";
     else lev = tmp + "";
   if (angelp(ob))    lev = "ANGL";
   if (immortalp(ob)) lev = "IMMO";
   if (musep(ob))     lev = "MUSE";
   if (assistp(ob))   lev = "ARCH";
   if (securep(ob))   lev = "META";
   if (adminp(ob))    lev = "ADMN";
   if (melp(ob))      lev = "MELZ";
   if (thoinp(ob))    lev = "TACO";
   if (laoisep(ob))   lev = "EVIL";
   if (zaxanp(ob))    lev = "MAGE";
   if (duukp(ob))     lev = "DUUK";
   if (ob->GetTestChar()) lev = "TEST";
   if (ob->GetProperty("assumed")) lev = " RP ";
  if ((tmp = query_idle(ob)) < 60) idle = "";
  else
  {
    x = time_units(tmp);
    if (x[0]) idle = sprintf("%2dw%:2dd", x[0], x[1]);
    else if (x[1]) idle = sprintf("%2dd%:2dh", x[1], x[2]);
    else if (x[2]) idle = sprintf("%2dh%:2dm", x[2], x[3]);
    else if (x[3]) idle = sprintf("%2dm%:2ds", x[3], x[4]);
  }

  ip = query_ip_name(ob);
  if (rank(ob) > rank(this_player())) ip = "<private>";
  if (!musep(this_player())) ip = "<hidden>";
  if (!environment(ob)) env = "no environment";
  else env = file_name(environment(ob));
  if (environment(ob)) {
  	if (vehiclep(environment(ob))) 
  	  env = base_name(environment(environment(ob)));
  	  }
  if (!strsrch(env, REALMS_DIRS)) 
    env = "~" + env[strlen(REALMS_DIRS)+1..];
  else if (!strsrch(env, DOMAINS_DIRS))
    env = "^"+env[strlen(DOMAINS_DIRS)+1..strlen(env)-1];
  env = short_file(env);
  return sprintf(formatString, age, lev, nom, ip, idle, blk, env);
}

static private string query_time() {
    string tzone;
    int x;

    tzone = (string)this_player()->GetTimeZone() || localtime(time())[LT_ZONE];
    x = (int)TIME_D->GetOffset(tzone) * 3600;
   return tzone + " time is: " + ctime(time());
}
    
string GetHelp (string blah) {
    return "Syntax: people \n\n"
      "Gives you a listing of people on "+mud_name()+".  Output is "
      "formatted into columns with the following meanings:\n"
      "    Total Logged Gametime \n"
      "    Level/Rank \n"
      "    Name\n"
      "    Login Site \n"
      "    Effort at Idleness\n"
      "    Channels Blocked (ALL), (I)mm, (O)oc \n"
      "    Mud Location \n\n"
      "People in the editor or in mail or posting will be marked with [].  "
      "People who are invisible to others, but not to you will be marked "
      "with ().  \n\nSee also: allstatus, morals, summ, who";
}
