#ifndef MORPHOLOGY_EXPOROTOR_H_
#define MORPHOLOGY_EXPOROTOR_H_

#include <vector>
#include "biodynamo.h"
#include "my_cell.h"
#include "soma_clustering_biology_modules.h"
#include "validation_criterion.h"



namespace bdm {


    template <typename TSimulation = Simulation<>>
    void WriteMorphology(std::string file_name) {
    auto* sim = TSimulation::GetActive();
    auto* rm = sim->GetResourceManager();
    auto my_cells = rm->template Get<MyCell>();

    
    int n = rm->GetNumSimObjects();
    
    //auto ptr = rm->GetSoPtr();
    
    std::cout<< "Number of Simulation object :"<< n<< std::endl;

    ofstream Soma_Clustering_Morphology;
    Soma_Clustering_Morphology.open(file_name,ios::out | ios::app);
   /*
    rm->ApplyOnAllElements([&](auto&& SO, const SoHandle&) {
    auto& pos = so.GetPosition();
    auto dia = so.GetDiameter();
    auto id = so.GetDaughter().GetNeuriteElementSoPtr();
    });
    */
    
        for (int i = 0; i < n; i++){
            auto thisCellType = (*my_cells)[i].GetCellType();
            auto position = (*my_cells)[i].GetPosition();
            Soma_Clustering_Morphology<<"S.No: "<<i<<" "<<"Cell_Type: "<<thisCellType<<"Position: "<<position[0]<<" "<<position[1]<<" "<<position[2]<<endl;
        }
        
}

} //namespace bdm 

#endif  // MORPHOLOGY_EXPOROTOR_H_
