#include "MazeBuilderMapData.h"

FMazeBuilderMapData::FMazeBuilderMapData()
{
}

FMazeBuilderMapData::~FMazeBuilderMapData()
{
}

FString FMazeBuilderMapData::ToString()
{
	FString str;
	for (int i = 0; i < strokeTable->Num(); i++)
	{
		str.Append((*strokeTable)[i]->ToString());
	}
	return str;
}

void FMazeBuilderMapData::Clear()
{
	strokeTable->Empty();
	max_row = 0;
	max_col = 0;
	min_row = 0;
	min_col = 0;
	MAX_LEVEL = 1;
}

/**获得当前点最近的地块中心点坐标*/
FVector FMazeBuilderMapData::FormatPos(FVector pos, float val, FVector gridSize)
{
	float x = pos.X;
	float z = pos.Z;
	// format "obj pre Pos %\n" obj.pos
	if (x > 0)
	{ //x轴正半轴
		x = (int)(x / val); //如果x值靠右，则右移
	}
	else
	{ //x轴负半轴
		x = (int)(x / val) - 1; //否则左移
	}

	if (z > 0)
	{ //z轴正半轴
		z = (int)(z / val);
	}
	else
	{ //y轴负半轴
		z = (int)(z / val) - 1;
	}
	//2D坐标修正,x为行号，z为列号,与max的左下角原点不同，这里的原点在右上角
	//format "x:% y:%\n" x y
	x = x + gridSize.X / 2;
	z = gridSize.Z / 2 + z;
	//Utility.DebugText("... x:"+x+" z:"+z+"\n");
	return *(new FVector(x, z, 0));
}

/**
* 游戏运行时获取地块信息
*
* @参数 row 地块行号
* @参数 col 地块列号
*/
TSharedPtr<FMazeBuilderStrokeInfo> FMazeBuilderMapData::GetStrokeInfoAt(int row, int col)
{
	for (int i = 0; i < strokeTable->Num(); i++)
	{
		if ((*strokeTable)[i]->row == row && (*strokeTable)[i]->col == col)
			return (*strokeTable)[i];
	}
	return NULL;
}

/**
* 地块编辑器编辑替换时使用
*
* @参数 row 地块行号
* @参数 col 地块列号
*/
AActor* FMazeBuilderMapData::GetStrokeAt(int row, int col)
{
	TSharedPtr<FMazeBuilderStrokeInfo> stroke_info = GetStrokeInfoAt(row, col);
	if (stroke_info != NULL) return stroke_info->obj;
	return NULL;
}

/**
* 获取地块上的原始块的名称,便于计算衍生地块名
*
* @参数 row 地块行号
* @参数 col 地块列号
*/
FString FMazeBuilderMapData::GetOldStrokeName(int row, int col)
{
	FString oldStrokeName = "0";
	AActor* oldStrokeObj = GetStrokeAt(row, col);
	if(oldStrokeObj) oldStrokeName = FMazeBuilderUltility::GetStrokeCode(oldStrokeObj->GetName());
	return oldStrokeName;
}

/**
* 从表中读取地图信息
*
*/

void FMazeBuilderMapData::ReadMapData(AActor mapRoot)
{
	strokeTable->Empty();
	FWorldContext worldContext = GEditor->GetEditorWorldContext();
	UWorld *world = (&worldContext)->World();
	if (world == NULL) return;
	ULevel *level = world->GetCurrentLevel();
	if (level == NULL) return;
	FString levelName = level->GetName();
	TArray<FString> OutTextArray;
	//string sceneName = SceneManager.GetActiveScene().name;
	bool loadSuccess = FMazeBuilderUltility::LoadTextToArray(levelName + "_mapData.txt", OutTextArray);
	if (loadSuccess)
	{
		// 这里处理表格数据，暂不处理
	}
	/*
	FString savePath = Application.dataPath + "/MapEditor/" + sceneName + "_mapData.txt";
	FileInfo fi = new FileInfo(savePath);
	FileStream fs = fi.Open(FileMode.OpenOrCreate);
	StreamReader sr = new StreamReader(fs);
	while (sr.Peek() >= 0)
	{
		string strLine = sr.ReadLine();
		//Utility.DebugText(strLine);
		// 重构Map信息
		string[] strs = strLine.Split('\t');
		STROKE_INFO stroke = new STROKE_INFO(strs[0], strs[1].ToInt(), strs[2].ToInt());
		stroke.row = strs[3].ToInt();
		stroke.col = strs[4].ToInt();
		stroke.path = new PATH_INFO(strs[6].ToInt() == 1, strs[7].ToInt() == 1, strs[8].ToInt() == 1, strs[9].ToInt() == 1);
		max_col = Mathf.Max(stroke.col, max_col);
		max_row = Mathf.Max(stroke.row, max_row);
		min_col = min_col == 0 ? stroke.col : Mathf.Min(min_col, stroke.col);
		min_row = min_row == 0 ? stroke.row : Mathf.Min(min_row, stroke.row);
		Vector3 pos = new Vector3(strs[5].ToFloat(), strs[6].ToFloat(), strs[7].ToFloat());
		Transform target = null;
		for (int i = 0; i < mapRoot.transform.childCount; i++)
		{
			Transform child = mapRoot.transform.GetChild(i);
			if (child.position == pos && child.name == strs[8])
			{
				target = child;
				break;
			}
		}
		if (target)
		{
			stroke.obj = target.gameObject;
			int lv = strs[8].Length;
			if (lv >= MAX_LEVEL) MAX_LEVEL = lv;
		}
		else
		{
			Utility.DebugText(strs[8] + "@[" + strs[5] + "," + strs[6] + "," + strs[7] + "]找不到");
		}
		this.strokeTable.Add(stroke);
	}
	sr.Dispose();
	sr.Close();
	*/
}

void FMazeBuilderMapData::SaveMapData()
{

	//保存表格数据
	/*
	EditorSceneManager.SaveScene(SceneManager.GetActiveScene());
	string sceneName = SceneManager.GetActiveScene().name;
	string savePath = Application.dataPath + "/MapEditor/" + sceneName + "_mapData.txt";
	Utility.DebugText(savePath);
	FileInfo fi = new FileInfo(savePath);
	FileStream fs = fi.Open(FileMode.Create);
	StreamWriter sw = new StreamWriter(fs);
	sw.Write(ToString());
	sw.Dispose();
	sw.Close();
	*/
}

/*
[ExecuteAlways]
public class MapData : MonoBehaviour {
	public static MapData instance;
	public MAP_DATA mapData = new MAP_DATA();

	void Awake()
	{
		instance = this;
		mapData.ReadMapData(this.gameObject);
		Utility.DebugText(mapData.MAX_LEVEL);
	}

	// Use this for initialization
	void Start() {
		SceneManager.sceneUnloaded += OnSceneUnLoaded;
	}

	// Update is called once per frame
	void Update() {

	}

	private void OnEnable() {
		SceneManager.sceneLoaded += OnSceneLoaded;
	}

	private void OnSceneLoaded(Scene scene, LoadSceneMode mode)
	{
#if UNITY_EDITOR
		mapData.ReadMapData(this.gameObject);
#endif
	}

	private void OnSceneUnLoaded(Scene scene)
	{
#if UNITY_EDITOR

#endif
	}
	*/