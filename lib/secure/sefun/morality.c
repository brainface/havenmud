/*    /secure/sefun/morality.c
 *    from the Nightmare IVr2 Object Library
 *    handles moral actions
 *    created by Descartes of Borg 951016
 */

int moral_act(object agent, object target, int amount) {
    if (agent->GetTestChar()) debug("Moral Act " + agent->GetName() + " " + amount);
    return (int)agent->eventMoralAct(amount);
}
