#ifndef xAODAnaHelpers_MuonHists_H
#define xAODAnaHelpers_MuonHists_H

#include "xAODAnaHelpers/IParticleHists.h"
#include <xAODMuon/MuonContainer.h>
#include "xAODAnaHelpers/Muon.h"
#include "xAODAnaHelpers/EventInfo.h"

ANA_MSG_HEADER(msgMuonHists)

class MuonHists : public IParticleHists
{
  public:


    MuonHists(std::string name, std::string detailStr, const std::string& prefix="muon", const std::string& titleprefix="muon");
    virtual ~MuonHists() ;

    virtual StatusCode initialize();
    virtual StatusCode execute( const xAOD::Muon* muon, float eventWeight, const xAOD::EventInfo* eventInfo = 0);
    virtual StatusCode execute( const xAH::Muon*  muon, float eventWeight, const xAH::EventInfo*  eventInfo = 0);
    using HistogramManager::book; // make other overloaded version of book() to show up in subclass
    using IParticleHists::execute; // overload

  protected:

    virtual StatusCode execute( const xAOD::IParticle* particle, float eventWeight, const xAOD::EventInfo* eventInfo = 0 );
    virtual StatusCode execute( const xAH::Particle* particle,   float eventWeight, const xAH::EventInfo*  eventInfo = 0 );

    // holds bools that control which histograms are filled
    HelperClasses::MuonInfoSwitch* m_infoSwitch;

  private:

    // Isolation
    std::map<std::string, TH1F *> m_isIsolated; //!

    TH1F* m_ptcone20				   ; //!
    TH1F* m_ptcone30				   ; //!
    TH1F* m_ptcone40				   ; //!
    TH1F* m_ptvarcone20				   ; //!
    TH1F* m_ptvarcone30				   ; //!
    TH1F* m_ptvarcone40				   ; //!
    TH1F* m_topoetcone20			   ; //!
    TH1F* m_topoetcone30			   ; //!
    TH1F* m_topoetcone40			   ; //!

    TH1F* m_ptcone20_rel				   ; //!
    TH1F* m_ptcone30_rel				   ; //!
    TH1F* m_ptcone40_rel				   ; //!
    TH1F* m_ptvarcone20_rel				   ; //!
    TH1F* m_ptvarcone30_rel				   ; //!
    TH1F* m_ptvarcone40_rel				   ; //!
    TH1F* m_topoetcone20_rel			   ; //!
    TH1F* m_topoetcone30_rel			   ; //!
    TH1F* m_topoetcone40_rel			   ; //!


    // quality
    std::map<std::string, TH1F *> m_quality; //!

};

#endif
