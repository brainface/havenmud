/*    /secure/daemon/finger.c
 *    from the Foundation II LPC Library
 *    gives finger information about users
 *    created by Descartes of Borg 950402
 *    Hacked up only extremely majorly by
 *    Zaf@Kailie
 *    And just a tad more by
 *    Zaxan@Kailie
 *   And of course by Duuk@Kailie
*    Suckup to Duuk code added by Balishae@Kailie
 */
 
#include <lib.h>
#include <daemons.h>
#include <clock.h>
#include <marriage.h>
#include "include/finger.h"
 
inherit LIB_DAEMON;
 
private int LoginTime, Level, BirthTime, CreatorBirth, WhereBlock;
private int Angel, TestChar, Retired;
private string CurrentUser, Short, CapName, RealName, Email;
private string LoginSite;
private class marriage *Marriages;
private string Domain, DomainTitle;
private string Sponsor;
private string Town, Race, Gender, HostSite;
private string Class, Guild, Long;
private string Rank;
private string *Titles, *Religion;
private string ReligionTitle;


static void create() {
    daemon::create();
    SetNoClean(1);
}
 
varargs string GetFinger(string who) {
    mapping mail_stat;
    object ob;
    string ret;
    mixed creator = 0;
    string tmp;
 
  if( !user_exists(who) )
          return capitalize(who) + " has yet to be born unto Kailie.";
        else if( !unguarded( (: restore_object, DIR_PLAYERS "/" + who[0..0] +
                              "/" + who :)) &&
                  !(creator = unguarded( (: restore_object, DIR_CRES "/" +
                              who[0..0] + "/" + who :) ) )) return 0;
        CurrentUser = who;
    if( !strsrch(save_file(who), DIR_CRES) ) creator = 1;
ret = replace_string(Short, "$N", CapName) + "%^RESET%^\n";  
        /* The + %^RESET%^ just in case they forget, so the rest isn't 
                colored like the name is. */
    if( (creator) && (lower_case(who) == "duuk") ){
       ret += capitalize(nominative(Gender))+" is the Supreme Deity of Kailie.\n";
       }
    if( (creator) && (member_group(who, "ADMIN")) &&
       (lower_case(who) != "duuk")) {
   ret += capitalize(nominative(Gender)) + " is a Greater Deity of Kailie.\n";
      }
    if( (creator) && (member_group(who, "SECURE"))  &&
         !member_group(who, "ADMIN")) {
       ret += capitalize(nominative(Gender))+" is a Metatron of Kailie.\n";
        }
    if( (creator) && (member_group(who, "ASSIST")) &&
        (!member_group(who, "SECURE")) ) {
       ret += capitalize(nominative(Gender))+" is an Arch-Angel of Kailie.\n";
        }
    if( (creator) && (member_group(who, "MUSE")) &&
	(!member_group(who, "ASSIST")) &&
	(!member_group(who, "SECURE")) ) {
	 ret += capitalize(nominative(Gender))+" is a Muse of Kailie.\n";
	 }
    if ( (creator) && (Angel) ) {
         ret += capitalize(nominative(Gender))+" is an Angel of Kailie.\n";
     }
    if( (creator) && (!member_group(who, "MUSE")) &&
	(!member_group(who, "ASSIST")) &&
       (!Angel) &&
        (!member_group(who, "ADMIN")) &&
	(!member_group(who, "SECURE")) ) {
	ret += capitalize(nominative(Gender))+" is an Immortal of Kailie.\n";
	}
  if (Retired) {
       ret += capitalize(nominative(Gender)) + " is Retired.\n";
     }
  if(TestChar) {
      ret += capitalize(nominative(Gender))+" is a Test Character of Kailie.\n";
    }
  if (creator) {
     ret += "Immortality Date : " + ctime(CreatorBirth) + "\n";
      ret += sprintf("Sponsor: %:-35s Spouse: %s\n",
             (Sponsor ? Sponsor : "None"),
          (sizeof(Marriages) && !(Marriages[0]->DivorceDate) ? 
                                  Marriages[0]->Spouse : "None") );
    }
        if (sizeof(Religion)) tmp = Religion[0];
       if (creator)
       ret += sprintf("Domain: %:-36s Religion: %s\n", 
			  ( (DomainTitle) ? DomainTitle + " ":"") +
              ( (Domain) ? Domain : "None"),
			  ( (ReligionTitle) ? ReligionTitle + " ":"") +
              (sizeof(Religion) ? (string)Religion[0] : "None") );
    if( !creator) {
        ret += capitalize(nominative(Gender))+" is " + (immortalp(this_player()) ? "a level "+Level+" member " : "")+ "of the " + Race + " race.\n";
        }
    if( !Email ) Email = "#CHANGE";
     if (creatorp(this_player()) && (!(angelp(this_player())))) {
                    ret += sprintf("In real life: %:-30s Email: %s\n", RealName ,
                           (Email[0]!='#' || (this_player(1) && archp(this_player(1))))
                            ? (Email[0] == '#' ? Email[1..] : Email) : "Unlisted");
        }
        /* Only cre+ get access to email/real name. */
    if( (ob = find_player(who)) ) {
    	if( !interactive(ob) ) ret += "(Net Dead) ";
    	if (ob->GetInvis() > rank(this_player()) ) {
    	  ret += "Last on " + ctime(LoginTime);
        } else { ret += "On since " + ctime(LoginTime); }
    } else {
      ret += "Last on " + ctime(LoginTime); 
     }
    
    if (creatorp(this_player()) && (!angelp(this_player()))) {
            if( !WhereBlock || (this_player(1) && adminp(this_player(1))) )
              ret += " from " + HostSite + "\n";
            else ret += "\n";
            mail_stat = (mapping)FOLDERS_D->mail_status(who);
            if( mail_stat["unread"] )
              ret += CapName + " has " + consolidate(mail_stat["unread"],
                                             "an unread letter") + ".\n";
        }
        else {
                ret += "\n";
                }
    if (sagep(this_player()) && LoginSite) {
         ret += "Last saved logout site was " + short_file(LoginSite) + "\n";
        }
    if( unguarded( (: file_size, user_path(who) + ".project" :) ) > 0 )
      ret += "ToDo List: " +
        unguarded( (: read_file, user_path(who) + ".project" :) ) + "\n";
    if( unguarded( (: file_size, user_path(who) + ".plan" :) ) > 0 )
      ret += "Plan:\n" +
        unguarded( (: read_file, user_path(who) + ".plan" :) ) + "\n";
    if( unguarded( (: file_size, user_path(who) + ".quote" :) ) > 0 )
      ret += "Quote:\n" +
        unguarded( (: read_file, user_path(who) + ".quote" :) ) + "\n";
    return ret;
}
 
mixed *GetRemoteFinger(string who) {
    mixed *tmp;
    object ob;
 
    who = convert_name(who);
    if( who != CurrentUser ) {
        if( !user_exists(who) ) return 0;
        else if( !unguarded( (: restore_object, DIR_PLAYERS "/" + who[0..0] +
                              "/" + who :)) &&
                !unguarded( (: restore_object, DIR_CRES "/" + who[0..0] +
                             "/" + who :) ) ) return 0;
        CurrentUser = who;
    }
    ob = find_player(who);
    tmp = ({ CapName, GetTitle(), RealName, ctime(LoginTime),
             (ob ? query_idle(ob) : -1), 0, "\n" });
    return tmp;
}
 
string GetTitle() {
    if( Short ) return Short;
    else if( Titles && sizeof(Titles) ) return Titles[0];
    else return CapName;
}
 
