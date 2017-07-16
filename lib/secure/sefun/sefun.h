#ifndef l_sefun_h
#define l_sefun_h

string absolute_path(string curr, string newpth);
int absolute_value(int x);
varargs string add_article(string str, int def);
int ambassadorp(object ob);
string architecture();
int archp(object ob);
string arrange_string(string str, int x);
string base_name(mixed val);
string cardinal(int x);
varargs string center(string str, int x);
varargs string conjunction(mixed expressions, string coordinator);
string consolidate(int x, string str);
string convert_name(string str);
varargs mixed convert_string(string str, int flag);
mixed copy(mixed val);
varargs int creatorp(object ob);
float currency_inflation(string type);
float currency_rate(string type);
int currency_mass(int x, string type);
int currency_value(int x, string str);
int destruct(object ob);
mixed *distinct_array(mixed *arr);
string domain(mixed val);
int domain_exists(string dmn);
object domain_master(mixed val);
varargs int effective_light(object ob);
varargs void event(string fun, int when, mixed *args, int reg);
mapping expand_keys(mapping mp);
int event_pending(object ob);
int exec(object target, object src);
int file_exists(string str);
string file_privs(string file);
string format_page(string *items, int columns);
varargs object get_object(string str, object player);
varargs mixed get_objects(string str, object player, int no_arr);
int hiddenp(object ob);
int high_mortalp(object ob);
string identify(mixed a);
string item_list(mixed *items);
int leaderp(object ob);
object *livings();
object load_object(string str);
void log_file(string fl, string msg);
int member_group(mixed who, string grp);
int moral_act(object who, object target, int amount);
string *mud_currencies();
string mud_name();
string mudlib();
string mudlib_version();
varargs int newbiep(object ob);
string nominative(mixed val);
string objective(mixed val);
string ordinal(int x);
object parse_objects(object where, string str);
mixed *path_file(mixed full_path);
float percent(mixed numerator, mixed denominator);
varargs int playerp(object ob);
string possessive(mixed val);
string possessive_noun(mixed val);
int query_date(int x);
string query_day_name(int x);
int query_host_port();
int query_hour(int x);
string GetIdle_string(object ob);
int query_minutes(int x);
string query_month(int x);
int query_night();
int query_reset_number();
string query_season(int x);
object query_snoop(object snoopee);
object query_snooping(object ob);
string query_time_of_day();
int query_year(int x);
string reflexive(mixed val);
string remove_article(string str);
string reverse_string(string str);
string save_file(string str);
varargs void say(mixed str, object ob);
void set_eval_limit(int x);
void set_privs(object ob, string str);
varargs void shout(mixed str, mixed exclude);
varargs void shutdown(int code);
varargs object snoop(object who, object target);
string strip_article(mixed val);
string strip_colours(string str);
void tell_object(object ob, mixed str);
varargs void tell_room(object ob, mixed str, mixed exclude);
varargs object this_agent(mixed val);
void time_event(string tod, function f);
object to_object(mixed target);
varargs int total_light(object ob);
string translate(string str, int prof, string lang);
string trim(string str);
mixed unguarded(function f);
object unique(string fn, int rare);
int user_exists(string str);
string user_path(string name);
string version();
varargs int visibility(object ob);
varargs int visible(object detectee_obj, object detector_obj);
varargs string wrap(string str, int width);
void write(string str);
int assistp(object);
int securep(object);
int adminp(object);
int duukp(object);
int sagep(object);
int legendp(object);
int demigodp(object);
mapping getopts(string arg, string *list);
varargs int* time_units(int seconds, int unit);

#endif /* l_sefun_h */


