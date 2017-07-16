/* sefuns for resolving and unresolving sphere from path
 * and vice versa
 */



string resolve_sphere(string path) {
  string words;
  string dir, file;

  if(sscanf(path, "/std/spells/%s/%s", dir, file) != 2) {
    error("**Non-spell base_name passed to resolve_sphere");
    return path;
    }
  words = implode(explode(dir, "_"), " ");
  return words;
}

string unresolve_sphere(string sphere) {
  string path;

  path = implode(explode(sphere, " "), "_");
  return ("/std/spells/" + path);
}


string resolve_song_type(string path) {
  string words;
  string dir, file;

  if(sscanf(path, "/std/songs/%s/%s", dir, file) != 2) {
    error("**Non-song base_name passed to resolve_song_type");
    return path;
    }
  words = implode(explode(dir, "_"), " ");
  return words;
}

string unresolve_song_type(string sphere) {
  string path;

  path = implode(explode(sphere, " "), "_");
  return ("/std/songs/" + path);
}

