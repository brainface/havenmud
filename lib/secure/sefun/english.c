/*    /adm/simul_efun/english.c
 *    from Dead Souls
 *    efuns for dealing with the oddity we know as the English language
 *    created by Descartes of Borg 940207
 *    Version: @(#) english.c 1.5@(#)
 *    Last modified: 97/01/01
 */

#include "/secure/sefun/pluralize.c"

varargs string add_article(string str, int def) {
    if( !stringp(str) ) {
	error("Bad argument 1 to add_article().\n");
    }
    if( def ) {
	str = remove_article(str);
	return "the " + str;
    }
    if( !strlen(str) ) {
	return str;
    }
    switch(str[0]) {
	case 'a': case 'e': case 'i': case 'o': case 'u':
	case 'A': case 'E': case 'I': case 'O': case 'U':
	return "an " + str;

	default:
	return "a " + str;
    }
}

string remove_article(string str) {
    string tmp;
    
    if( !stringp(str) ) error("Bad argument 1 to remove_article().\n");
    if( sscanf(str, "the %s", tmp) ) return tmp;
    if( sscanf(str, "a %s", tmp) ) return tmp;
    if( sscanf(str, "an %s", tmp) ) return tmp;
    return str;
}

string array explode_list(string list) {
    string array items;
    string one, two;

    list = lower_case(list);
    if( sscanf(list, "%s and %s", one, two) == 2 ) {
	items = explode(one, ",") + explode(two, ",");
    }
    else {
	items = explode(list, ",");
    }
    items = map(items, function(string str) {
                           if( !str ) {
			       return 0;
			   }
			   str = trim(str);
			   if( strlen(str) > 4 && str[0..3] == "and " ) {
			       str = str[4..];
			   }
	                   str = remove_article(str);
			   if( strlen(str) > 3 && str[0..2] == "my " ) {
			       str = str[3..];
			   }
			   return str;
                       });
    return filter(items, (: $1 && $1 != "" :));
}

varargs string item_list(mixed array items...) {
    mapping list = ([]);
    string str;
    int maxi;
    
    if( !sizeof(items) ){
	error("Bad argument 1 to item_list().\n");
    }
    if( arrayp(items[0]) ) {
	if( !sizeof(items[0]) ) {
	    return "";
	}
	items = items[0];
    }
    foreach(mixed value in items) {
        if( objectp(value) ) {
	    if( living(value) ) {
		value = value->GetName();
	    }
	    else {
		value = value->GetShort();
	    }
	}
	if( !value ) {
	    continue;
	}
	if( !list[value] ) {
	    list[value] = 1;
	}
	else {
	    list[value]++;
	}
    }
    maxi = sizeof(items = keys(list));
    if( maxi < 1 ) {
	return "";
    }
    str = consolidate(list[items[0]], items[0]);
    if( maxi == 1 ) {
	return str;
    }
    if( maxi > 2 ) {
	str += ",";
    }
    for(int i=1; i<maxi; i++) {
	if( i == maxi-1 ) {
	    str += " and ";
	}
	else {
	    str += " ";
	}
        str += consolidate(list[items[i]], items[i]);
	if( i < maxi-1 ) {
	    str += ",";
	}
    }
    return str;
}
		       
string possessive_noun(mixed val) {
    if (!val) val = previous_object();
    if(objectp(val)) val = (string)val->GetName();
    else if(!stringp(val)) error("Bad argument 1 to possessive_noun().\n");
    switch(val[strlen(val)-1]) {
        case 'x': case 'z': case 's': return sprintf("%s'", val);
        default: return sprintf("%s's", val);
    }
}

string possessive(mixed val) {
    if (!val) val = previous_object();
    switch(objectp(val) ? (string)val->GetGender() : (string)val) {
        case "male": return "his";
        case "female": return "her";
        default: return "its";
    }
}

string strip_article(mixed val) {
    int x;

    if( objectp(val) ) val = (string)val->GetShort();
    x = strlen(val);
    if( x <= 2 ) return val;
    if( val[0..1] == "a " || val[0..1] == "A " ) return val[2..];
    if( x <= 3 ) return val;
    if( val[0..2] == "an " || val[0..2] == "An " ) return val[3..];
    if( x <= 4 ) return val;
    if( val[0..3] == "the " || val[0..3] == "The " ) return val[4..];
    return val;
}
    
string nominative(mixed val) {
    switch(objectp(val) ? (string)val->GetGender() : (string)val) {
        case "male": return "he";
        case "female": return "she";
        default: return "it";
    }
}

string objective(mixed val) {
    switch(objectp(val) ? (string)val->GetGender() : (string)val) {
        case "male": return "him";
        case "female": return "her";
        default: return "it";
    }
}

string reflexive(mixed val) { return sprintf("%sself", objective(val)); }

string cardinal(int x) {
    string tmp;
    int a;

    if(!x) return "zero";
    if(x < 0) {
        tmp = "negative ";
        x = absolute_value(x);
    }
    else tmp = "";
    switch(x) {
        case 1: return tmp+"one";
        case 2: return tmp+"two";
        case 3: return tmp+"three";
        case 4: return tmp+"four";
        case 5: return tmp+"five";
        case 6: return tmp+"six";
        case 7: return tmp+"seven";
        case 8: return tmp+"eight";
        case 9: return tmp+"nine";
        case 10: return tmp+"ten";
        case 11: return tmp+"eleven";
        case 12: return tmp+"twelve";
        case 13: return tmp+"thirteen";
        case 14: return tmp+"fourteen";
        case 15: return tmp+"fifteen";
        case 16: return tmp+"sixteen";
        case 17: return tmp+"seventeen";
        case 18: return tmp+"eighteen";
        case 19: return tmp+"nineteen";
        case 20: return tmp+"twenty";
        default:
            if(x > 1000000000) return "over a billion";
            else if(a = x /1000000) {
                if(x = x %1000000) 
                  return sprintf("%s million %s", cardinal(a), cardinal(x));
                else return sprintf("%s million", cardinal(a));
            }
            else if(a = x / 1000) {
                if(x = x % 1000) 
                  return sprintf("%s thousand %s", cardinal(a), cardinal(x));
                else return sprintf("%s thousand", cardinal(a));
            }
            else if(a = x / 100) {
                if(x = x % 100) 
                  return sprintf("%s hundred %s", cardinal(a), cardinal(x));
                else return sprintf("%s hundred", cardinal(a));
            }
            else {
                a = x / 10;
                if(x = x % 10) tmp = "-"+cardinal(x);
                else tmp = "";
                switch(a) {
                    case 2: return "twenty"+tmp;
                    case 3: return "thirty"+tmp;
                    case 4: return "forty"+tmp;
                    case 5: return "fifty"+tmp;
                    case 6: return "sixty"+tmp;
                    case 7: return "seventy"+tmp;
                    case 8: return "eighty"+tmp;
                    case 9: return "ninety"+tmp;
                    default: return "error";
                }
            }
    }
}

varargs string conjunction(mixed expressions, string coordinator) {
    int size;
    string tmp;

    if(!expressions) error("Bad argument 1 to conjunction().\n");
    else if(stringp(expressions)) expressions = ({ expressions });
    else if(!pointerp(expressions))
      error("Bad argument 1 to conjunction().\n");

    size = sizeof(expressions);
    if (!sizeof(expressions)) return "";
    if(size < 2) return expressions[0];

    // Form the conjunction.
    if(!coordinator) coordinator = "and";
    tmp = "";
    for(int i = 0; i < size; i++) {
      tmp += expressions[i];
      if(i < size - 2) tmp += ", ";
      else return tmp + " " + coordinator + " " + expressions[size - 1];
    }
}

string consolidate(int x, string str) {
    string array words;
    string tmp;

    if( x == 1 || !sizeof(str) ) return str;
    words = explode(str, " ");
    if( sscanf(words[<1], "(%s)", tmp) ) {
        if( sizeof(words) == 1 ) 
            return "(" + consolidate(x, tmp) + ")";
        else return consolidate(x, implode(words[0..<2], " ")) + 
                    " (" + tmp + ")";
    }
    if( sscanf(words[<1], "[%s]", tmp) ) {
        if( sizeof(words) == 1 )
            return "[" + consolidate(x, tmp) + "]";
        else return consolidate(x, implode(words[0..<2], " ")) +
                    " [" + tmp + "]";
    }
    if( words[0][0..1] == "%^" ) {
        string array parts;
        string part, colour = "";
        int i = 0;

        parts = explode(words[0], "%^");
        if( sizeof(parts) == 1 ) {
            if( sizeof(words) == 1 ) return words[0];
            else return words[0] + consolidate(x, implode(words[1..], " "));
        }
        
        foreach(part in parts) {
            if( sizeof(part) && !sizeof(strip_colours("%^" + part + "%^")) )
                colour += ("%^" + part + "%^"); 
            else return colour + consolidate(x, 
                        (implode(parts[i..], "%^")) + " " + 
                        (implode(words[1..], " ")) );
            i++;
        }
        return words[0] + " " + consolidate(x, implode(words[1..], " "));
       
    }
    if( member_array(lower_case(strip_colours(words[0])), 
             ({"a", "an", "the", "one"}) ) > -1 ) words = words[1..];
    return (cardinal(x) + " " + pluralize(implode(words, " ")));
}
