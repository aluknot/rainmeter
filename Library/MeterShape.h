/* Copyright (C) 2016 Rainmeter Project Developers
 *
 * This Source Code Form is subject to the terms of the GNU General Public
 * License; either version 2 of the License, or (at your option) any later
 * version. If a copy of the GPL was not distributed with this file, You can
 * obtain one at <https://www.gnu.org/licenses/gpl-2.0.html>. */

#ifndef __METERSHAPE_H__
#define __METERSHAPE_H__

#include "../Common/Gfx/Shape.h"
#include "Meter.h"

class MeterShape : public Meter
{
public:
	MeterShape(Skin* skin, const WCHAR* name);
	virtual ~MeterShape();

	MeterShape(const MeterShape& other) = delete;
	MeterShape& operator=(MeterShape other) = delete;

	UINT GetTypeID() override { return TypeID<MeterShape>(); }

	virtual bool Update();
	virtual bool Draw(Gfx::Canvas& canvas);

	bool HitTest(int x, int y);

protected:
	virtual void ReadOptions(ConfigParser& parser, const WCHAR* section);
	virtual void BindMeasures(ConfigParser& parser, const WCHAR* section);

private:
	void Dispose();

	bool CreateShape(std::vector<std::wstring>& args, bool& isCombined);
	bool CreateCombinedShape(size_t shapeId, std::vector<std::wstring>& args);

	void ParseModifiers(std::vector<std::wstring>& args, ConfigParser& parser, const WCHAR* section, bool recursive = false);

	std::vector<Gfx::Shape*> m_Shapes;
};

#endif
