// Transfered to cmd by Amelia
#include <lib.h>

inherit LIB_DAEMON;

static string *DamageDegree = ({
  "is in critical condition!",
  "is battered beyond recognition.",
  "is severely wounded",
  "is terribly damaged.",
  "is in bad shape.",
  "is hurting.",
  "has a few bruises.",
  "is in decent shape.",
  "is in very good shape.",
  "is in excellent shape.",
});

mixed cmd(string args) {
   object who;
   string ret = "";
   string *limbs;
   mapping mp = ([ ]);
   int i, damage;
   int *key;
   if(creatorp(this_player()) && !args) {
      return "Syntax:  body <target>";
   }
   if(!creatorp(this_player())) {
      who = this_player();
      if(!who->GetSleeping()) {
         send_messages( ({ "check" }),"$agent_name $agent_verb "
            "$agent_reflexive over for injuries.",who,0,
            environment(who));
      }
      this_player()->eventPrint("Your bodily damage report:");
   }
   else {
      if(!who = find_living(args)) {
         return "Unable to find target.";
      }
      if(duukp(who)) { return "He has a great body .. uhh ... yeah."; }
      if(creatorp(who)) { return "Oooo, sexy!"; }
      this_player()->eventPrint("%^BOLD%^%^BLUE%^" +
         who->GetCapName() + "'s bodily damage report:%^RESET%^");
   }
   if(!who) { who = this_player(); }

  i = sizeof(limbs = (string *)who->GetLimbs());
  while(i--) {
    damage = to_int( percent( (int)who->GetHealthPoints(limbs[i]),
                              (int)who->GetMaxHealthPoints(limbs[i]) ));
    if( !mp[damage] ) mp[damage] = ({ limbs[i] });
    else mp[damage] += ({ limbs[i] });
  }
  i = sizeof(key = sort_array(keys(mp), 1));
  foreach(damage in key) {
    string str;
    string color;
    int x;
    i = sizeof(limbs = mp[damage]);
    while(i--) {
      switch(damage) {
        case 0..3: color = "%^BOLD%^%^RED%^"; break;
        case 4..10: color = "%^RED%^";        break;
        case 11..20: color = "%^YELLOW%^";    break;
        default: color = "";
      }
      if( damage > 97 )
        str = "Your "+ limbs[i] + " is in perfect condition.";
      else if( damage < 4 )
        str = "Your "+ limbs[i] +" is about to fall off!";
      else {
        x = damage / 10;
        if(x>9) x = 9;
        str = "Your "+ limbs[i] +" "+ DamageDegree[x];
      }
      ret += (color + str + "%^RESET%^\n");
    }
  }
  if( i = sizeof(limbs = (string *)who->GetMissingLimbs()) ) {
      ret += "\nYou are missing ";
      switch(i) {
      case 0: break;
      case 1: ret += "a "+limbs[0]+"."; break;
      case 2: ret += "a "+limbs[0]+" and a "+limbs[1]+"."; break;
      default:  ret += "a "+implode(limbs[0..(i-2)], ", ")+" and "
                "a "+limbs[i-1]+".";
    }
  }
  this_player()->eventPage(explode(ret, "\n"), "info");
  return 1;
}

string GetHelp(string str) {
  if( creatorp(this_player()) )
    return "Syntax: <body [living]>\n\n"
           "This command will display the current limb damage "
           "statistics of the living object named, listed from "
           "most damaged to least.";
  else
    return "Syntax: <body>\n\n"
           "This command will display your current limb damage "
           "statistics.  The limbs will be displayed in order "
           "of the most damaged to the least.";
}
