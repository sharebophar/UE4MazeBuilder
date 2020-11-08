#include "MazeBuilderStrokeInfo.h"

FMazeBuilderStrokeInfo::~FMazeBuilderStrokeInfo()
{
}

FMazeBuilderStrokeInfo::FMazeBuilderStrokeInfo(FString p, int i, int l)
{
	this->name = p;
	this->trans_type = i;
	this->level = l;
	this->path = MakeShareable(new FMazeBuilderPathInfo(p));
}

//存储txt格式可在跨平台时使用
FString FMazeBuilderStrokeInfo::ToString()
{
	if (obj != NULL)
	{
		FString sb = FString();
		sb.Append(FString(name));
		sb.Append("\t");
		sb.Append(FString::FromInt(trans_type));
		sb.Append("\t");
		sb.Append(FString::FromInt(level));
		sb.Append("\t");
		sb.Append(FString::FromInt(row));
		sb.Append("\t");
		sb.Append(FString::FromInt(col));
		sb.Append("\t");
		FVector pos;
		obj->GetActorTransform().TransformPosition(pos);
		sb.Append(FString::SanitizeFloat(pos.X));
		sb.Append("\t");
		sb.Append(FString::SanitizeFloat(pos.Y));
		sb.Append("\t");
		sb.Append(FString::SanitizeFloat(pos.Z));
		sb.Append("\t");
		sb.Append(obj->GetName());
		sb.Append("\t");
		sb.Append(path->ToString());
		sb.Append("\r\n");
		return sb;
	}
	else
	{
		return "";
	}
}