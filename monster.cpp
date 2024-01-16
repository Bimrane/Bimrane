bool sightMonster::wallBetween(int x, int y) const
{
    /* Détecte la présence d'un mur entre deux points
    en utilisant l'algorithme de ligne de vue de Bresenham */

    int diffx = abs(x - getX());
    int diffy = abs(y - getY());
    int movetox = (getX() < x) ? 1 : -1;
    int movetoy = (getY() < y) ? 1 : -1;
    int error = diffx - diffy;
    int x1 = getX();
    int y1 = getY();

    while (x1 != x || y1 != y) 
    {
        if (mvinch(y1,x1) == '#')
            return true; // Il y a un mur entre les deux points
    
        int error2 = 2 * err;
        if (error2 > -diffy) 
        {
            error -= diffy;
            x1 += movetox;
        }
        if (error2 < diffx)
        {
            error += diffx;
            y1 += movetoy;
        }
    }
    return false; // Pas de mur entre les deux points
}
