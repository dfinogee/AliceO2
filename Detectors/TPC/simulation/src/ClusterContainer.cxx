#include "ClusterContainer.h"
#include "Cluster.h"

#include "FairLogger.h"

#include "TClonesArray.h"
#include "TError.h"                // for R__ASSERT

using namespace AliceO2::TPC;

//________________________________________________________________________
ClusterContainer::ClusterContainer():
  mNclusters(0),
  mClusterArray(nullptr)
{}

//________________________________________________________________________
ClusterContainer::~ClusterContainer()
{
  delete mClusterArray;
}

//________________________________________________________________________
void ClusterContainer::InitArray(const Char_t* clusterType)
{
  R__ASSERT(!mClusterArray);
  mClusterArray = new TClonesArray(clusterType);
  
  // Brute force test that clusterType is derived from AliceO2::TPC::Cluster 
  Cluster *cluster = 
    dynamic_cast<Cluster*>(mClusterArray->ConstructedAt(mNclusters));
  R__ASSERT(cluster);

  // reset array after test
  Reset();
}

//________________________________________________________________________
void ClusterContainer::Reset()
{
  R__ASSERT(mClusterArray);
  mClusterArray->Clear();
  mNclusters = 0;
}

//________________________________________________________________________
Cluster* ClusterContainer::AddCluster(Int_t cru, Int_t row, 
				      Float_t qtot, Float_t qmax, 
				      Float_t meanpad, Float_t meantime, 
				      Float_t sigmapad, Float_t sigmatime)
{
  R__ASSERT(mClusterArray);
  Cluster *cluster = 
    dynamic_cast<Cluster*>(mClusterArray->ConstructedAt(mNclusters));
  mNclusters++;
  cluster->setParameters(cru, row, qtot, qmax, meanpad, meantime, 
			 sigmapad, sigmatime);
  return cluster;
}


//________________________________________________________________________
void ClusterContainer::FillOutputContainer(TClonesArray *output)
{
  for(Int_t n = 0; n < mNclusters; n++) {
    
    Cluster *clusterOut = 
      dynamic_cast<Cluster*>(mClusterArray->ConstructedAt(n));
    
Cluster* cluster = dynamic_cast<Cluster*>(mClusterArray->At(mNclusters));
    clusterOut->Copy(*cluster);
  }
}