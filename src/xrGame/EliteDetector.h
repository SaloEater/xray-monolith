#pragma once
#include "CustomDetector.h"
#include "level.h"
#include "hudsound.h"

class CUIArtefactDetectorElite;

class CEliteDetector : public CCustomDetector
{
	typedef CCustomDetector inherited;
public:
	CEliteDetector();
	virtual ~CEliteDetector();
	virtual void Load(LPCSTR section);
	virtual void OnH_B_Independent(bool just_before_destroy);
	virtual void render_item_3d_ui();
	virtual LPCSTR ui_xml_tag() const { return "elite"; }
protected:
	virtual void UpdateAf();
	virtual void CreateUI();
	virtual void ResetUI();
	CUIArtefactDetectorElite& ui();

	HUD_SOUND_ITEM		m_snd_af_found;
	xr_set<CArtefact*>	m_alerted_artefacts;
};


class CScientificDetector : public CEliteDetector
{
	typedef CEliteDetector inherited;
public:
	CScientificDetector();
	virtual ~CScientificDetector();
	virtual void Load(LPCSTR section);
	virtual void OnH_B_Independent(bool just_before_destroy);
	virtual void shedule_Update(u32 dt);
	virtual LPCSTR ui_xml_tag() const { return "scientific"; }
protected:
	virtual void UpdateWork();
	CZoneList m_zones;
};
