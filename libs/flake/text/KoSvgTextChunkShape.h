/*
 *  Copyright (c) 2017 Dmitry Kazakov <dimula73@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef KOSVGTEXTCHUNKSHAPE_H
#define KOSVGTEXTCHUNKSHAPE_H

#include "kritaflake_export.h"

#include <KoShapeContainer.h>
#include <SvgShape.h>

class KoSvgTextProperties;
class KoSvgTextChunkShapePrivate;
class KoSvgTextChunkShapeLayoutInterface;

class KRITAFLAKE_EXPORT KoSvgTextChunkShape : public KoShapeContainer, public SvgShape
{
public:
    KoSvgTextChunkShape();
    KoSvgTextChunkShape(const KoSvgTextChunkShape &rhs);
    ~KoSvgTextChunkShape() override;

    KoShape* cloneShape() const;

    void paintComponent(QPainter &painter, const KoViewConverter &converter, KoShapePaintingContext &paintContext) override;
    void saveOdf(KoShapeSavingContext &Context) const override;
    bool loadOdf(const KoXmlElement &element, KoShapeLoadingContext &Context) override;
    bool saveSvg(SvgSavingContext &context) override;
    bool loadSvg(const KoXmlElement &element, SvgLoadingContext &context) override;
    bool loadSvgTextNode(const KoXmlText &text, SvgLoadingContext &context);
    void normalizeCharTransformations();

    KoSvgTextProperties textProperties() const;
    bool isTextNode() const;

    KoSvgTextChunkShapeLayoutInterface* layoutInterface();

protected:
    KoSvgTextChunkShape(KoSvgTextChunkShapePrivate *dd);

private:
    Q_DECLARE_PRIVATE(KoSvgTextChunkShape)
};

#endif // KOSVGTEXTCHUNKSHAPE_H
