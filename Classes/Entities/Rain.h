#ifndef CONST_RAIN_H
#define CONST_RAIN_H

#include "Entity.h"

class Rain : public Entity
{
    protected:
        // ===========================================================
        // Inner Classes
        // ===========================================================

        // ===========================================================
        // Constants
        // ===========================================================

        // ===========================================================
        // Fields
        // ===========================================================

        // ===========================================================
        // Constructors
        // ===========================================================
    
        Rain();

        // ===========================================================
        // Methods
        // ===========================================================

        // ===========================================================
        // Virtual Methods
        // ===========================================================

    private:
        // ===========================================================
        // Inner Classes
        // ===========================================================

        // ===========================================================
        // Constants
        // ===========================================================

        // ===========================================================
        // Fields
        // ===========================================================

        // ===========================================================
        // Constructors
        // ===========================================================

        // ===========================================================
        // Methods
        // ===========================================================
        
        // ===========================================================
        // Virtual Methods
        // ===========================================================

    public:
        // ===========================================================
        // Inner Classes
        // ===========================================================

        // ===========================================================
        // Constants
        // ===========================================================

        // ===========================================================
        // Fields
        // ===========================================================

        // ===========================================================
        // Constructors
        // ===========================================================
    
        static Rain* create();

        // ===========================================================
        // Methods
        // ===========================================================
    
        void update(float pDeltaTime);
        
        // ===========================================================
        // Virtual Methods
        // ===========================================================
    
        void onCreate();
        void onDestroy();
    
        Rain* deepCopy();
};

#endif