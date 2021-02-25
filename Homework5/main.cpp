#include "WHO.h"
#include "Covid19.h"

int main(int argc, char const *argv[])
{
    Covid19 c19(1.1f, 5, false, "SJBDYSLNHSJDMJDUESKD", "brazil");
    //c19.print(cout);
    CovidGB cgb(1, 5, true, "SJBDYSLNHSJDMJDUESSD", "israel", 5);
    //cgb.print(cout);
    CovidSA csa(5, 2, false, "ANJTOYLUJSJDMANXZCKS", "italy", 0);
    //csa.print(cout);
    CovidKZ ckz(11.1, 20, false, "TTBDYSLNHSJDMJDUESKD", "china", 9, 9.9, "AGGTC");
    //ckz.print(cout);

    WHO who(nullptr, 0, "israel", 8000000, 3000);
    try
    {
        who.addVirus(c19);
        who.addVirus(cgb);
        who.addVirus(csa);
        who.addVirus(ckz);
    }
    catch (const invalid_argument &e)
    {
        cerr << e.what() << endl;
    }
    catch (bad_alloc)
    {
        cerr << "Out of Mem" << endl;
    }
    catch (...)
    {
        cerr << "shouldn't get here" << endl;
    }

    who.print();
    ///////
    try
    {
        who.changeMutation("TTBDYSLNHSJDMJDUESKD", "AAGTGCCTACGTTGCCATTG");
        cout << endl << endl;
        who.print();
    }
    catch (...)
    {
        cerr << "shouldn't get here" << endl;
    }
    ///////
    try
    {
        cout << endl << endl;
        who.changeMutation("ANJTOYLUJSJDMANXZCKS", "TCG");
    }
    catch (const char *e)
    {
        //std::cerr << e << endl; // it already prents in 'changeMutation' as instructed
    }
    catch (...)
    {
        cerr << "shouldn't get here" << endl;
    }
    ///////

    try
    {
        WHO who1 = who;
        cout << endl << "who1" << endl;
        who1.print();
        who1.emptyArray();
        who1.print();
        who1 = who;
        who.print();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
