/*    /verbs/common/help.c
 *    from the Nightmare IVr2 Object Library
 *    created by Descartes of Borg 951021
 *    Version: @(#) help.c 1.11@(#)
 *    Last Modified: 96/11/01
 */

#include <lib.h>
#include <dirs.h>
#include <daemons.h>
#include <std.h>

inherit LIB_DAEMON;

static private string Error;
static private mapping Indices;

static private void LoadIndices();
string GetHelp(string str);
string GetHelpByIndex(string index, string topic);
string GetTopic(string index, string topic);
varargs string array GetIndices(string topic);

static void create() {
    daemon::create();
    SetNoClean(1);
    Error = 0;
    LoadIndices();
}

int CanAccess(object who, string index) {
    switch(index) {
    case "admin commands":
    return archp(who);

    case "muse commands" :
    case "muse documents" :
      return musep(who);
    
    case "immortal commands": case "immortal documents":
    case "library objects": case "daemon objects":
    case "lib documents":
    return creatorp(who);

    default:
    return 1;
    }
}
    
static private void LoadIndices() {
    string array tmp, tmp_spells;
    function f;
    string dir;
    
    f = function(string str) { return str[0..<3]; };
  Indices = ([]);


  
  tmp = get_dir(DIR_ADMIN_VERBS + "/*.c") + get_dir(DIR_ADMIN_CMDS + "/*.c")
      + get_dir(DIR_SECURE_ADMIN_CMDS + "/*.c");
  Indices["admin commands"] = map(tmp, f);

  tmp = get_dir(DIR_MUSE_CMDS + "/*.c") + 
  get_dir(DIR_SECURE_MUSE_CMDS + "/*.c");
  Indices["muse commands"] = map(tmp, f);
  
  tmp = get_dir(DIR_HELP "/stats/");
  Indices["stat documents"] = tmp;
  
  tmp = get_dir(DIR_HELP "/skills/");
  Indices["skill documents"] = tmp;
  

  tmp = get_dir(DIR_COMMON_VERBS+"/*.c") +
	  get_dir(DIR_COMMON_CMDS + "/*.c") +
    get_dir(DIR_SECURE_COMMON_CMDS + "/*.c") +
	  get_dir(DIR_PLAYER_CMDS+"/*.c") +
    get_dir(DIR_SECURE_PLAYER_CMDS + "/*.c")
    ;
  Indices["commands"] = map(tmp, f);
  
  tmp = get_dir(DIR_ROOM_VERBS + "/*.c") +	
	      get_dir(DIR_VEHICLE_VERBS + "/*.c") +
	      get_dir(DIR_ITEM_VERBS + "/*.c") +
               get_dir(DIR_CRAFTING_VERBS + "/*.c") +
	      get_dir(DIR_PLAYER_VERBS+"/*.c") 
	      ;
  Indices["verbs"] = map(tmp, f);	      

  tmp = get_dir(DIR_ACTION_VERBS + "/*.c");
  Indices["combat actions"] = map(tmp, f);
  
  tmp = get_dir(DIR_CREATOR_VERBS+"/*.c") + get_dir(DIR_CREATOR_CMDS+"/*.c")
      + get_dir(DIR_SECURE_CREATOR_CMDS + "/*.c");
  Indices["immortal commands"] = map(tmp, f);

    if( tmp = get_dir(DIR_PLAYER_HELP + "/") ) Indices["player documents"] = tmp;
      else Indices["player documents"] = ({});
    if( tmp = get_dir(DIR_CREATOR_HELP "/") ) Indices["immortal documents"] = tmp;
      else Indices["immortal document"] = ({});
    if (tmp = get_dir("/doc/help/towns/")) Indices["towns"] = tmp;
     else Indices["towns"] = ({ });
    if( tmp = (string array)CLASSES_D->GetClasses() ) Indices["classes"] = tmp - ({ "animal" });
      else Indices["classes"] = ({});
    if( tmp = (string array)RACES_D->GetRaces(1) ) Indices["races"] = tmp;
      else Indices["races"] = ({});
    if( tmp = get_dir(DIR_RELIGION_HELP "/") ) Indices["religions"] = tmp;
      else Indices["religions"] = ({});
    if (tmp = get_dir(DIR_LORE "/")) Indices["lore"] = tmp;
      else Indices["lore"] = ({ });        
    
    Indices["library objects"] = ({});
    foreach(dir in ({ DIR_LIB, DIR_SECURE_LIB })){
	    if( !(tmp = get_dir(dir + "/*.c")) ) continue;
	      else Indices["library objects"] += map(tmp, (: $(dir)+"/"+$1[0..<3] :));
    }
}

string GetHelp(string str) {
    string *tmp;
    string topic;
    int x;
    
    Error = 0;
    if( !str || str == "" || str == "help" ) {
	return ("Syntax: <help>\n"
		"        <help index>\n"
		"        <help TOPIC>\n"
		"        <help INDEX TOPIC>\n\n"
		"Without an argument, you get this help screen.  The same "
		"applies for trying to get help on the help command.  With "
		"an argument, you are given information on the topic you "
		"specified.  The special topic, \"help index\", puts you into "
		"a menu driven index of categories for which help exists.  In "
		"some cases, the same help topic will exist in two separate "
		"categories.  If help tells you that you have asked for "
		"help on such a topic, you may specify the index from which "
		"it comes by using the index name help gives you.  For "
		"example:\n"
		"> help list\n"
		"There exists help for \"list\" in the following indices:\n"
		"commands, channels\n"
		">\n"
		"You could then type \"help player commands list\" to get "
		"the help for the list player command.\n\n"
		"In general, most commands have only a single index, so there "
		"is generally no need to specify the index.\n"
		"Finally, to help you better understand how to issue commands "
		"on Haven, you should check out the document "
		"\"help syntax\".\n\n"
		"See also: faq, index, syntax");
    }
   if (str == "soul" || str == "feelings" || str == "souls") {
	return (string)SOUL_D->GetHelp("feelings");
    }
    tmp = GetIndices(str);
    if( sizeof(tmp) == 1 ) {
	return GetHelpByIndex(tmp[0], str);
    }
    else if( sizeof(tmp) > 1 ) {
	Error = "There exists help for \"" + str + "\" under the following "
	    "indices:\n" + implode(tmp, ", ");
	return 0;
    }
    topic = "";
    str = trim(str);
    while( (x = strsrch(str, " ")) != -1 ) {
	if( topic != "" ) {
	    topic = topic + " " + str[0..(x-1)];
	}
	else {
	    topic = str[0..(x-1)];
	}
	str = str[(x+1)..];
	if( Indices[topic] && strlen(str) ) {
	    return GetHelpByIndex(topic, str);
	}
    }
    Error = "Help for the topic \"" + str + "\" could not be found.";
    return 0;
}

string GetHelpByIndex(string index, string topic) {
    mixed array tmparr, fun;
    string spell, spell_dir;
    mapping tmpmap;
    object ob;
    string help, file, tmpstr;

    if( this_player() && !CanAccess(this_player(), index) ) {
	Error = "You do not have access to that information.";
	return 0;
    }
    switch(index) {
    case "admin commands": case "immortal commands": case "commands":
    case "muse commands": case "spirit commands": case "combat styles":
    case "verbs":case "combat actions":
	switch(index) {
        case "admin commands":
	    if( file_exists( DIR_ADMIN_VERBS + "/" + topic + ".c") )
		file = DIR_ADMIN_VERBS + "/" + topic;
	    else if( file_exists( DIR_ADMIN_CMDS + "/" + topic + ".c") )
		file = DIR_ADMIN_CMDS + "/" + topic;
	    else file = DIR_SECURE_ADMIN_CMDS + "/" + topic;
	    break;
	    
        case "combat styles":
         file = base_name(STYLES_D->GetStyle(topic));
              break;

        case "immortal commands":
	    if( file_exists( DIR_CREATOR_VERBS + "/" + topic + ".c") )
		file = DIR_CREATOR_VERBS + "/" + topic;
	    else if( file_exists(DIR_CREATOR_CMDS + "/" + topic + ".c") )
		file = DIR_CREATOR_CMDS + "/" + topic;
	    else file = DIR_SECURE_CREATOR_CMDS + "/" + topic;
	    break;      
       case "muse commands" :
            if( file_exists( DIR_SAGE_CMDS + "/" + topic + ".c") )
              file = DIR_SAGE_CMDS + "/" + topic;
        else if( file_exists( DIR_SECURE_SAGE_CMDS + "/" + topic + ".c") )
              file = DIR_SECURE_SAGE_CMDS + "/" + topic;
             break;
      
	    
        case "commands":case "verbs":case "combat actions":
	    foreach(string directory in ({ DIR_COMMON_VERBS,
					       DIR_COMMON_CMDS,
					       DIR_SECURE_COMMON_CMDS,
					       DIR_ITEM_VERBS,
					       DIR_VEHICLE_VERBS,
					       DIR_PLAYER_VERBS,
					       DIR_PLAYER_CMDS,
					       DIR_SECURE_PLAYER_CMDS,
					       DIR_ROOM_VERBS,
					       DIR_ACTION_VERBS, })) {
		if( file_exists(directory + "/" + topic + ".c") ) {
		    file = directory + "/" + topic;
		    break;
		}
	    }
           
        }
        
        if( !file_exists(file + ".c") ) {
	    Error = "No such " + index[0..<2] + " exists.";
	    return 0;
	}
	if( catch(help = file->GetHelp(topic)) ) {
	    Error = "An error occurred in attempting to access help.";
	    return 0;
	}
	if( !help ) {
	    string *syn, *pd;
	    string line;
	    
	    pd = regexp(explode(parse_dump(), "\n"), file[1..]);
	    syn = ({});
	    foreach(line in pd) {
		sscanf(line, "%*s"+file[1..]+") %s", tmpstr);
		syn += ({ tmpstr });
	    }
	    if( !sizeof(syn) ) {
		if( function_exists("help", load_object(file)) ) {
		    Error = "This help may be out of date.";
		    file->help();
		    return 0;
		}
		Error = "Unable to locate any syntax information on " +
		    topic + ".";
		return 0;
	    }
	    help = "Syntax: " + topic + " " + syn[0] + "\n";
	    if( sizeof(syn) == 1 ) help += "\n";
	    else {
		foreach(line in syn[1..])
		    help += "        " + topic + " " + line + "\n";
		help += "\n";
	    }
	    help += "No detailed documentation exists for this command.";
	}
	help = "Index: %^GREEN%^" + index + "%^RESET%^\n" +
	    "Topic: %^GREEN%^" + topic + "%^RESET%^\n\n" + help;
	return help;
	
    case "player documents": case "immortal documents":
    case "skill documents": case "lib documents":
    case "stat documents": case "sage documents":
    case "immortal profiles": case "spirit documents":
    case "stat documents": case "lore":
	switch(index) {
        case "player documents":
	    file = DIR_PLAYER_HELP "/" + topic;
	    break;
	    
        case "immortal documents":
	    file = DIR_CREATOR_HELP "/" + topic;
	    break;

       case "immortal profiles":
          file = DIR_HELP "/profiles/" + topic;
          break;
       case "stat documents":
          file = DIR_HELP "/stats/" + topic;
          break;
	     case "skill documents":
	        file = DIR_HELP "/skills/" + topic;
	        break;
	     case "lore":
	        file = DIR_LORE + "/" + topic;
	        break;
	    
	}
	if( !file_exists(file) ) {
	    Error = "No such " + index[0..<2] + " is available.";
	    return 0;
	}
	if( !(help = read_file(file)) ) {
	    Error = "The document " + topic + " was empty.";
	    return 0;
	}
	help = "Index: %^GREEN%^" + index + "%^RESET%^\n" +
	    "Topic: %^GREEN%^" + topic + "%^RESET%^\n\n" + help;
	return help;
	
    case "library objects":
	topic = GetTopic(index, topic);
	if( catch(help = topic->GetHelp(topic)) ) {
	    Error = "An error occurred in attempting to access help.";
	    return 0;
	}
	if( !help ) {
	    help = "No synopsis available for this object.\n\n";
	}
	else {
	    help = "Synopsis:\n" + help + "\n\n";
	}
	tmparr = stat(topic + ".c");
	tmpstr = "Object: " + topic + "\n"
	    "Last Modified: " + ctime(tmparr[1]) + "\n";
	if( tmparr[2] ) {
	    tmpstr += "Last Loaded: " + ctime(tmparr[2]) + "\n\n";
	}
	tmparr = inherit_list(ob = find_object(topic));
	if( !sizeof(tmparr) ) {
	    tmpstr += "No inherited objects\n\n";
	}
	else {
	    tmpstr += "Inherits:\n" + format_page(tmparr, 4) + "\n";
	}
	tmparr = functions(ob, 1);
	tmpmap = ([]);
	foreach(fun in tmparr) {
	    if( function_exists(fun[0], ob) != topic ) {
		continue;
	    }
	    if( fun[0] == "#global_init#" ) {
		continue;
	    }
	    if( tmpmap[fun[0]] ) {
		continue;
	    }
	    else {
		tmpmap[fun[0]] = ([ "type" : fun[2],
				  "args" : (fun[1] ? fun[3..] : ({})) ]);
	    }
	}
	help = tmpstr + help;
	if( !sizeof(tmparr) ) {
	    help += "No functions\n\n";
	}
	else {
	    string fnc;
	    
	    help += "Functions:\n";
	    tmparr = sort_array(keys(tmpmap), 1);
	    foreach(fnc in tmparr) {
		help += tmpmap[fnc]["type"] + fnc + "(" +
		    implode(tmpmap[fnc]["args"], ", ") + ")\n";
	    }
	}
	help = "Index: %^GREEN%^" + index + "%^RESET%^\n" +
	    "Topic: %^GREEN%^" + topic + "%^RESET%^\n\n" + help;
	return help;
	
    case "daemon objects":
	topic = GetTopic(index, topic);
	if( catch(help = topic->GetHelp(topic)) ) {
	    Error = "An error occurred in attempting to access help.";
	    return 0;
	}
	if( !help ) {
	    help = "No synopsis available for this object.\n\n";
	}
	else {
	    help = "Synopsis:\n" + help + "\n\n";
	}
	tmparr = stat(topic + ".c");
	tmpstr = "Object: " + topic + "\n"
	    "Last Modified: " + ctime(tmparr[1]) + "\n";
	if( tmparr[2] ) tmpstr += "Last Loaded: " + ctime(tmparr[2]) + "\n\n";
	tmparr = inherit_list(ob = find_object(topic));
	if( !sizeof(tmparr) ) tmpstr += "No inherited objects\n\n";
	else tmpstr += "Inherits:\n" + format_page(tmparr, 4) + "\n";
	tmparr = functions(ob, 1);
	tmpmap = ([]);
	foreach(fun in tmparr) {
	    if( function_exists(fun[0], ob) != topic ) continue;
	    if( fun[0] == "#global_init#" ) continue;
	    if( tmpmap[fun[0]] ) continue;
	    else tmpmap[fun[0]] = ([ "type" : fun[2],
				   "args" : (fun[1] ?  fun[3..] : ({})) ]);
	}
	help = tmpstr + help;
	if( !sizeof(tmparr) ) help += "No functions\n\n";
	else {
	    string fnc;
	    
	    help += "Functions:\n";
	    tmparr = sort_array(keys(tmpmap), 1);
	    foreach(fnc in tmparr)
		help += tmpmap[fnc]["type"] + fnc + "(" +
		implode(tmpmap[fnc]["args"], ", ") + ")\n";
	}
	help = "Index: %^GREEN%^" + index + "%^RESET%^\n" +
	    "Topic: %^GREEN%^" + topic + "%^RESET%^\n\n" + help;
	return help;    
	
    case "religions": case "religion":
	if( file_exists(DIR_RELIGION_HELP "/" + topic) ) {
	    help = read_file(DIR_RELIGION_HELP "/" + topic);
	    help = "Index: %^GREEN%^" + index + "%^RESET%^\n" +
		  "Topic: %^GREEN%^" + topic + "%^RESET%^\n\n" + help;
		  topic = capitalize(topic);
                  topic = replace_string(topic,"-cult"," Cult"); // rath cult fix.
           help += "\n\n";
	    help += "\n  Religion Moral Code: " + MORALITY_D->GetReligionAlignment(topic) + 
	            " (limited to " + MORALITY_D->GetStringRange(topic) +" morals)";
	    help += "\n" + MORALITY_D->GetReligionSkillsHelp(topic);
	    return help;
	}
	  case "lore":
	if (file_exists(DIR_LORE "/" + topic)) {
	    help = read_file(DIR_LORE "/" + topic);
	    help = "Index: %^GREEN%^" + index + "%^RESET%^\n" +
		  "Topic: %^GREEN%^" + topic + "%^RESET%^\n\n" + help;
		  topic = capitalize(topic);
	    return help;
	  }
	Error = "No such religion exists.";
	return 0;
	
    case "races":
        if( help = (string)RACES_D->GetHelp(topic) ) {
	    help = "Index: %^GREEN%^" + index + "%^RESET%^\n" +
		"Topic: %^GREEN%^" + topic + "%^RESET%^\n\n" + help;
	    if( file_exists(DIR_RACE_HELP + "/" + topic) )
		help += read_file(DIR_RACE_HELP + "/" + topic);
	    return help;
	}
	Error = "No such race exists.";
	return 0;
	
	
    case "classes":
        if( help = (string)CLASSES_D->GetHelp(topic) ) {
	    help = "Index: %^GREEN%^" + index + "%^RESET%^\n" +
		"Topic: %^GREEN%^" + topic + "%^RESET%^\n\n" + help;
	    if( file_exists(DIR_CLASS_HELP + "/" + topic) )
		help += read_file(DIR_CLASS_HELP + "/" + topic);
	    return help;
	}
	Error = "No such class exists.";
	return 0;
    case "towns":
           if ( file_exists("/doc/help/towns/" + topic)) {
               help = "Index: %^GREEN%^" + index + "%^RESET%^\n" +
               "Topic: %^GREEN%^" + topic + "%^RESET%^\n";
               help += "\n";
               help += read_file("/doc/help/towns/" + topic);
               return help;
             }
          Error = "No town information is available for " + topic + ".";
          return 0;
	
    default:
	Error = "No help exists for the index " + index + ".";
	return 0;
    }
}

varargs string array GetIndices(string topic) {
    string array topics, val;
    string ind, tmp;

    if( !topic ) {
	return sort_array(keys(Indices), 1);
    }
    topics = ({});
    foreach(ind, val in Indices) {
	if( !CanAccess(this_player(), ind) ) {
	    continue;
	}
	tmp = GetTopic(ind, topic);
	if( member_array(tmp, val) != -1 ) {
	    topics += ({ ind });
	}
    }
    return sort_array(topics, 1);
}

string GetTopic(string index, string topic) {
    string array dirlist;
    string dir;
    
    if( index != "library objects" && index != "daemon objects" ) {
	return topic;
    }
    if( index == "library objects" ) {
	dirlist = ({ DIR_LIB, DIR_SECURE_LIB });
    }
    else {
	dirlist = ({ DIR_DAEMONS, DIR_SECURE_DAEMONS });
    }
    if( strlen(topic) > 2 && topic[<2..] == ".c" ) {
	topic = topic[0..<3];
    }
    if( file_exists(topic + ".c") ) {
	return topic;
    }
    foreach(dir in dirlist) {
	if( file_exists(dir + "/" + topic + ".c") ) {
	    return dir + "/" + topic;
	}
    }
    return 0;
}

string array GetTopics(string index) {
    string array topics = Indices[index];

    if( !topics ) {
	return 0;
    }
    else {
	return sort_array(topics, 1);
    }
}

string GetLastError() {
    return Error;
}

void Reload() {
    LoadIndices();
}
