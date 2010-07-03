#include "general.h"
#include "engine.h"

General::General(const QString &name, const QString &kingdom, int max_hp, bool male, const QString &pixmap_dir)
    :kingdom(kingdom), max_hp(max_hp), male(male), pixmap_dir(pixmap_dir)
{
    QChar leader_symbol('!');
    if(name.contains(leader_symbol)){
        QString copy = name;
        setObjectName(copy.remove(leader_symbol));
        lord = true;
    }else{
        setObjectName(name);
        lord = false;
    }
}

int General::getMaxHp() const{
    return max_hp;
}

QString General::getKingdom() const{
    return kingdom;
}

bool General::isMale() const{
    return male;
}

bool General::isFemale() const{
    return !male;
}

bool General::isLord() const{
    return lord;
}

QString General::getPixmapPath(const QString &category) const{
    return QString("%1/%2/%3.png").arg(pixmap_dir).arg(category).arg(objectName());
}

QString General::getKingdomPath() const{
    return QString("%1/kingdom/%2").arg(pixmap_dir).arg(kingdom);
}

