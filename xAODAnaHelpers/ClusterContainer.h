#ifndef xAODAnaHelpers_ClusterContainer_H
#define xAODAnaHelpers_ClusterContainer_H

#include <TTree.h>
#include <TLorentzVector.h>

#include <vector>
#include <string>

#include "xAODCaloEvent/CaloClusterContainer.h"

#include <xAODAnaHelpers/HelperClasses.h>

#include <xAODAnaHelpers/Cluster.h>
#include <xAODAnaHelpers/ParticleContainer.h>

typedef SG::AuxElement::Accessor< std::vector< float > > floatAccessor ;

namespace xAH {

  class ClusterContainer : public ParticleContainer<Cluster,HelperClasses::ClusterInfoSwitch>
    {
    public:
      ClusterContainer(const std::string& name = "clus", const std::string& detailStr="", float units = 1e3, bool mc = false);
      virtual ~ClusterContainer();

      virtual void setTree(TTree *tree);
      virtual void setBranches(TTree *tree);
      virtual void clear();
      virtual void FillCluster( const xAOD::CaloCluster* cluster );
      virtual void FillCluster( const xAOD::IParticle* particle );
      using ParticleContainer::setTree; // make other overloaded version of execute() to show up in subclass

    protected:
      virtual void updateParticle(uint idx, Cluster& cluster);

    };
}
#endif // xAODAnaHelpers_ClusterContainer_H
