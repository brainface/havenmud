/*    /secure/obj/sefun.c
 *    from Dead Souls
 *    the mud sefun object
 *    created by Descartes of Borg 940213
 */

#pragma save_binary

#include <lib.h>
#include <daemons.h>
#include <commands.h>
#include <objects.h>
#include <dirs.h>
#include <armour_types.h>
#include "sefun.h"

#include "/secure/sefun/absolute_value.c"
#include "/secure/sefun/base_name.c"
#include "/secure/sefun/communications.c"
#include "/secure/sefun/convert_name.c"
#include "/secure/sefun/copy.c"
#include "/secure/sefun/distinct_array.c"
#include "/secure/sefun/domains.c"
#include "/secure/sefun/economy.c"
#include "/secure/sefun/english.c"
#include "/secure/sefun/events.c"
#include "/secure/sefun/expand_keys.c"
#include "/secure/sefun/files.c"
#include "/secure/sefun/format_page.c"
#include "/secure/sefun/get_object.c"
#include "/secure/sefun/getopts.c"
#include "/secure/sefun/identify.c"
#include "/secure/sefun/interface.c"
#include "/secure/sefun/light.c"
#include "/secure/sefun/load_object.c"
#include "/secure/sefun/log_file.c"
#include "/secure/sefun/messaging.c"
#include "/secure/sefun/morality.c"
#include "/secure/sefun/mtime.c"
#include "/secure/sefun/mud_info.c"
#include "/secure/sefun/ordinal.c"
#include "/secure/sefun/parse_objects.c"
#include "/secure/sefun/path_file.c"
#include "/secure/sefun/percent.c"
#include "/secure/sefun/persist.c"
#include "/secure/sefun/pointers.c"
#include "/secure/sefun/query_time_of_day.c"
#include "/secure/sefun/absolute_path.c"
#include "/secure/sefun/security.c"
#include "/secure/sefun/short_file.c"
#include "/secure/sefun/sphere.c"
#include "/secure/sefun/strings.c"
#include "/secure/sefun/tail.c"
#include "/secure/sefun/this_agent.c"
#include "/secure/sefun/time.c"
#include "/secure/sefun/time_units.c"
#include "/secure/sefun/to_object.c"
#include "/secure/sefun/translate.c"
#include "/secure/sefun/user_exists.c"
#include "/secure/sefun/user_path.c"
#include "/secure/sefun/viking.c"
#include "/secure/sefun/visible.c"

object *users()
{
   return filter(efun::users(), (: $1 && !undefinedp($1) :));
}

object *players() {
  return filter( users(), (: noncreatorp :) );
}

int userp(object ob) {
  if (!ob) ob = previous_object();
  if (base_name(ob) == LIB_CONNECT) return 1;
  if (strsrch(base_name(ob), "/secure/save/players/") != -1) return 1;
  return efun::userp(ob);
}


int destruct(object ob) {
    string *privs;
    string tmp;

    if(undefinedp(ob)) return efun::destruct(ob);
    if(previous_object(0) == ob) return efun::destruct(ob);
    if(!(tmp = query_privs(previous_object(0)))) return 0;
    if(member_array(PRIV_SECURE, explode(tmp, ":")) != -1)
      return efun::destruct(ob);
    privs = ({ file_privs(file_name(ob)) });
    if((int)master()->valid_apply(({ "ASSIST" }) + privs))
      return efun::destruct(ob);
    else return 0;
}

varargs void shutdown(int code) {
    if(!((int)master()->valid_apply(({})))) return;
    if(this_player())
      log_file("shutdowns", (string)this_player()->GetCapName()+
        " shutdown "+mud_name()+" at "+ctime(time())+"\n");
    else log_file("shutdowns", "Game shutdown by "+
      file_name(previous_object(0))+" at "+ctime(time())+"\n");
    efun::shutdown(code);
}

varargs object snoop(object who, object target) {
    if(!target)                   
      return efun::snoop(who);
    if(!creatorp(who))            
      return 0;
    if (rank(who) < rank(target)) 
      return 0;
    return efun::snoop(who, target);
}

object query_snoop(object ob) {
    if(!userp(previous_object(0))) return 0;
    return efun::query_snoop(ob);
}

object query_snooping(object ob) {
    if(!((int)master()->valid_apply(({})))) return 0;
    else return efun::query_snooping(ob);
}


void write(string str) {
    if(this_player()) message("my_action", str, this_player());
    else efun::write(str);
}

object *livings() {
    return efun::livings() - (efun::livings() - objects());
}

void set_privs(object ob, string str) { return; }

void set_eval_limit(int x) {
    if(previous_object() != master()) return;
    efun::set_eval_limit(x);
}

void notify_fail(string str) {
    if( !this_player() ) return;
    if( str[<1..] == "\n" ) str = str[0..<2];
    this_player()->SetCommandFail(str);
}

/* want to handle colours, but do it efficiently as possible */
string capitalize(string str) {
    string *words, *tmp;
    int i;
    
    /* error condition, let it look like an efun */
    if( !str || str == "" ) return efun::capitalize(str);
    /* most strings are not colour strings */
    if( strlen(str) < 2 || str[0..1] != "%^" ) return efun::capitalize(str);
    /* god help us */
    words = explode(str, " ");
    /* ok, this is strange, but remember, colours are all caps :) */
    tmp = explode(words[0], "%^");
    for(i=0; i<sizeof(tmp); i++) tmp[i] = efun::capitalize(tmp[i]);
    words[0] = "%^" + implode(tmp, "%^") + "%^";
    return implode(words, " ");
}


int immortal_exists(string nom) {
    string str;

    if( !nom ) return 0;
    str = DIR_CRES "/" + nom[0..0] + "/" + nom + __SAVE_EXTENSION__;
    return unguarded( (: file_size, str :)) > -1;
}

int exec(object target, object src) {
   string caller = base_name(previous_object());

  if(  (caller != LIB_CONNECT) &&
       (caller != CMD_ENCRE) &&
       (caller != CMD_DECRE) &&
       (caller != CMD_ASSUME) &&
       (caller != OBJ_ASSUME)
      ) return 0;
  return efun::exec(target, src);
}

int random(int seed) {
	int sig = 1;
	
        seed = to_int(seed);
	if (seed < 0) sig = -1;
	return (efun::random(absolute_value(seed)) * sig);
}

void replace_program(string str) {
  write("No replace_program here!");
  return;
}

int replaceable(mixed o) {
  return 0;
}

void debug(string bug) {
   CHAT_D->eventSendChannel("SEFUN", "debug", bug+" [from "+short_file(base_name(previous_object()))+"]");
}

string armour_type_string(int x) {
  switch(x) {
    case A_RING       :  return "ring"; break;  
    case A_GLOVE      :  return "glove"; break;  
    case A_LONG_GLOVE :  return "long glove"; break;  
    case A_BOOT       :  return "boot"; break;  
    case A_LONG_BOOT  :  return "long boot"; break;  
    case A_SOCK       :  return "sock"; break;  
    case A_LONG_SOCK  :  return "long sock"; break;  
    case A_HELMET     :  return "helmet"; break;  
    case A_VISOR      :  return "visor"; break;  
    case A_PANTS      :  return "pants"; break;  
    case A_BELT       :  return "belt"; break;  
    case A_SHIRT      :  return "shirt"; break;   
    case A_CLOAK      :  return "cloak"; break; 
    case A_VEST       :  return "vest"; break; 
    case A_WEAPON     :  return "weapon"; break; 
    case A_SHIELD     :  return "shield"; break; 
    case A_ARMOUR     :  return "full armour"; break; 
    case A_AMULET     :  return "amulet"; break; 
    case A_BODY_ARMOUR:  return "body armour"; break;
    default           :  return "unknown"; break;
  }
}
 
int spammy_resets() {
  return 0;
}

/*  fixing a crashbug - Didn't work

varargs string read_file(string file, int start_line, int number_of_lines) { 
	if (file_size(file) < 1) return ""; 
	return efun::read_file(file, start_line, number_of_lines); 
}

*/
