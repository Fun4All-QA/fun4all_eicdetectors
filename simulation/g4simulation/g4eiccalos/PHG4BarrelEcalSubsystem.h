// Tell emacs that this is a C++ source
//  -*- C++ -*-.
#ifndef G4DETECTORS_PHG4BARRELECALSUBSYSTEM_H
#define G4DETECTORS_PHG4BARRELECALSUBSYSTEM_H

#include <g4detectors/PHG4DetectorSubsystem.h>

#include <string>  // for string

class PHCompositeNode;
class PHG4Detector;
class PHG4DisplayAction;
class PHG4BarrelEcalDetector;
class PHG4SteppingAction;

class PHG4BarrelEcalSubsystem : public PHG4DetectorSubsystem
{
 public:
  /** Constructor
   */
  PHG4BarrelEcalSubsystem(const std::string &name = "FORWARD_HCAL_DEFAULT", const int layer = 0);

  /** Destructor
   */
  virtual ~PHG4BarrelEcalSubsystem();

  /**
     Creates the m_Detector object
     Creates the stepping action
     Creates relevant hit nodes that will be populated by the stepping action and stored in the output DST
  */
  int InitRunSubsystem(PHCompositeNode *) override;

  /** Event processing
   */
  int process_event(PHCompositeNode *) override;

  //! Print info (from SubsysReco)
  void Print(const std::string &what = "ALL") const override;

  /** Accessors (reimplemented)
   */
  PHG4Detector *GetDetector() const override;
  PHG4SteppingAction *GetSteppingAction() const override { return m_SteppingAction; }
  PHG4DisplayAction *GetDisplayAction() const override { return m_DisplayAction; }

  /** Set mapping file for calorimeter towers
   */
  void SetTowerMappingFile(const std::string &filename);

  void SetUseFeTungstenAbsorber(int /* useTungsten */) { set_int_param("absorber_FeTungsten", 1); };

 private:
  void SetDefaultParameters() override;

  /** Pointer to the Geant4 implementation of the detector
   */
  PHG4BarrelEcalDetector *m_Detector = nullptr;

  /** Stepping action
   */
  PHG4SteppingAction *m_SteppingAction = nullptr;
  //! display attribute setting
  /*! derives from PHG4DisplayAction */
  PHG4DisplayAction *m_DisplayAction = nullptr;

  std::string m_HitNodeName;
  std::string m_AbsorberNodeName;
  std::string m_SupportNodeName;
};

#endif
