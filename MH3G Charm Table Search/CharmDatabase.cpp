#include "stdafx.h"
#include "CharmDatabase.h"
#include <fstream>
#include <cmath>

using namespace System;

ref struct StaticData
{
#pragma region Skill1Table
	static array< array< unsigned char >^ >^ skill1_table =
	{
		//mystery
		{
			3, 1, 8, // 気絶
			1, 1, 5, // 麻痺
			2, 1, 5, // 睡眠
			0, 1, 5, // 毒
			6, 1, 7, // 対防御DOWN
			100, 1, 10, // 盗み無効
			4, 1, 7, // 耐泥耐雪
			5, 1, 7, // 抗菌
			24, 1, 7, // 耐震
			25, 1, 10, // 耐暑
			26, 1, 10, // 耐寒
			9, 1, 4, // 攻撃
			16, 1, 4, // 達人
			78, 1, 6, // 爆弾強化
			76, 1, 6, // 笛
			77, 1, 6, // 砲術
			10, 1, 4, // 防御
			43, 1, 6, // 火耐性
			44, 1, 6, // 水耐性
			45, 1, 6, // 雷耐性
			46, 1, 6, // 氷耐性
			47, 1, 6, // 龍耐性
			11, 1, 8, // 体力
			101, 1, 8, // 高速設置
			82, 1, 8, // 腹減り
			83, 1, 10, // 食いしん坊
			98, 1, 8, // 運搬
			88, 1, 10, // 採取
			89, 1, 8, // 高速収集
			90, 1, 10, // 気まぐれ
			80, 1, 8, // 広域
			97, 1, 8, // 千里眼
			86, 1, 10, // 調合成功率
			87, 1, 8, // 調合数
			81, 1, 8, // 効果持続
			96, 1, 8, // 観察眼
			7, 1, 8, // こやし
			99, 1, 8, // 狩人
			32, 1, 8, // 気配
			62, 1, 6, // 通常弾追加
			63, 1, 6, // 貫通弾追加
			64, 1, 6, // 散弾追加
			65, 1, 6, // 榴弾追加
			66, 1, 6, // 拡散弾追加
			67, 1, 6, // 斬裂弾追加
			58, 1, 6, // 精密射撃
			70, 1, 7, // 麻痺瓶追加
			71, 1, 8, // 睡眠瓶追加
			69, 1, 8, // 毒瓶追加
			72, 1, 7, // 強撃瓶追加
			73, 1, 8, // 接撃瓶追加
			74, 1, 8, // 減気瓶追加
			102, 1, 8, // 燃鱗
			104, 1, 6, // 水流
			105, 1, 6, // 泳ぎ
			103, 1, 7, // 酸素
			115, 1, 3, // 采配
			116, 1, 3, // 号令
			75, 1, 6, // 爆破瓶追加
			68, 1, 6, // 爆破弾追加
		},

		//shining
		{
			3, 1, 8, // 気絶
			1, 1, 5, // 麻痺
			2, 1, 5, // 睡眠
			0, 1, 5, // 毒
			6, 1, 7, // 対防御DOWN
			4, 1, 7, // 耐泥耐雪
			5, 1, 7, // 抗菌
			24, 1, 7, // 耐震
			23, 1, 4, // 風圧
			9, 1, 4, // 攻撃
			16, 1, 4, // 達人
			36, 1, 4, // 特殊攻撃
			37, 1, 7, // 火属性攻撃
			38, 1, 7, // 水属性攻撃
			39, 1, 7, // 雷属性攻撃
			40, 1, 7, // 氷属性攻撃
			41, 1, 7, // 龍属性攻撃
			19, 1, 6, // KO
			20, 1, 6, // 減気攻撃
			107, 1, 6, // 底力
			78, 1, 6, // 爆弾強化
			76, 1, 6, // 笛
			77, 1, 6, // 砲術
			10, 1, 4, // 防御
			43, 1, 6, // 火耐性
			44, 1, 6, // 水耐性
			45, 1, 6, // 雷耐性
			46, 1, 6, // 氷耐性
			47, 1, 6, // 龍耐性
			13, 1, 7, // 加護
			11, 1, 8, // 体力
			12, 1, 7, // 回復速度
			79, 1, 6, // 回復量
			29, 1, 6, // 回避性能
			14, 1, 6, // 納刀
			101, 1, 8, // 高速設置
			84, 1, 4, // 食事
			21, 1, 6, // 体術
			28, 1, 6, // 気力回復
			82, 1, 8, // 腹減り
			98, 1, 8, // 運搬
			80, 1, 8, // 広域
			97, 1, 8, // 千里眼
			33, 1, 6, // ガード性能
			34, 1, 4, // ガード強化
			51, 1, 4, // 研ぎ師
			62, 1, 6, // 通常弾追加
			63, 1, 6, // 貫通弾追加
			64, 1, 6, // 散弾追加
			65, 1, 6, // 榴弾追加
			66, 1, 6, // 拡散弾追加
			67, 1, 6, // 斬裂弾追加
			54, 1, 4, // 装填速度
			58, 1, 6, // 精密射撃
			102, 1, 8, // 燃鱗
			104, 1, 6, // 水流
			105, 1, 6, // 泳ぎ
			103, 1, 7, // 酸素
			115, 1, 5, // 采配
			116, 1, 5, // 号令
			75, 1, 6, // 爆破瓶追加
			68, 1, 6, // 爆破弾追加
		},

		//ancient
		{
			22, 1, 5, // 聴覚保護
			23, 1, 5, // 風圧
			36, 1, 6, // 特殊攻撃
			37, 1, 7, // 火属性攻撃
			38, 1, 7, // 水属性攻撃
			39, 1, 7, // 雷属性攻撃
			40, 1, 7, // 氷属性攻撃
			41, 1, 7, // 龍属性攻撃
			17, 1, 5, // 痛撃
			18, 1, 5, // 重撃
			15, 1, 5, // 溜め短縮
			109, 1, 6, // 本気
			19, 1, 6, // KO
			20, 1, 6, // 減気攻撃
			107, 1, 6, // 底力
			113, 1, 5, // 属性耐性
			13, 1, 7, // 加護
			79, 1, 6, // 回復量
			29, 1, 6, // 回避性能
			30, 1, 6, // 回避距離
			14, 1, 6, // 納刀
			84, 1, 5, // 食事
			27, 1, 5, // スタミナ
			21, 1, 6, // 体術
			28, 1, 6, // 気力回復
			48, 1, 5, // 斬れ味
			33, 1, 6, // ガード性能
			34, 1, 6, // ガード強化
			59, 1, 5, // 通常弾強化
			60, 1, 5, // 貫通弾強化
			61, 1, 5, // 散弾強化
			54, 1, 6, // 装填速度
			57, 1, 5, // 反動
			115, 1, 7, // 采配
			116, 1, 7, // 号令
		},

		//weathered
		{
			22, 3, 5, // 聴覚保護
			23, 3, 5, // 風圧
			36, 3, 6, // 特殊攻撃
			42, 1, 5, // 属性攻撃
			37, 3, 7, // 火属性攻撃
			38, 3, 7, // 水属性攻撃
			39, 3, 7, // 雷属性攻撃
			40, 3, 7, // 氷属性攻撃
			41, 3, 7, // 龍属性攻撃
			17, 3, 5, // 痛撃
			18, 3, 5, // 重撃
			55, 1, 5, // 装填数
			15, 3, 5, // 溜め短縮
			109, 3, 6, // 本気
			19, 3, 6, // KO
			20, 3, 6, // 減気攻撃
			107, 3, 6, // 底力
			113, 3, 5, // 属性耐性
			13, 3, 7, // 加護
			79, 3, 6, // 回復量
			29, 3, 6, // 回避性能
			30, 3, 6, // 回避距離
			14, 3, 6, // 納刀
			84, 3, 5, // 食事
			27, 3, 5, // スタミナ
			21, 3, 6, // 体術
			28, 3, 6, // 気力回復
			93, 1, 5, // 運気
			95, 1, 5, // 捕獲
			94, 1, 5, // 剥ぎ取り
			49, 1, 5, // 匠
			50, 1, 5, // 剣術
			48, 3, 5, // 斬れ味
			53, 1, 5, // 抜刀会心
			52, 1, 5, // 抜刀減気
			33, 3, 6, // ガード性能
			34, 3, 6, // ガード強化
			59, 3, 5, // 通常弾強化
			60, 3, 5, // 貫通弾強化
			61, 3, 5, // 散弾強化
			56, 1, 5, // 速射
			54, 3, 6, // 装填速度
			57, 3, 5, // 反動
			112, 1, 3, // 属性解放
			108, 1, 5, // 逆境
			85, 1, 3, // 肉食
			31, 1, 3, // 飛距離
			91, 1, 3, // ハチミツ
			8, 1, 3, // 細菌学
			110, 1, 3, // 闘魂
			111, 1, 3, // 無傷
			114, 1, 5, // 根性
			115, 3, 7, // 采配
			116, 3, 7, // 号令
			92, 3, 7, // 護石王
		},
	};
#pragma endregion
#pragma region Skill2Table
	static array< array< signed char >^ >^ skill2_table =
	{
		//mystery
		{},

		//shining
		{
			3, -10, 10, // 気絶
			1, -10, 7, // 麻痺
			2, -10, 7, // 睡眠
			0, -10, 7, // 毒
			6, -10, 8, // 対防御DOWN
			100, -10, 10, // 盗み無効
			4, -10, 8, // 耐泥耐雪
			5, -10, 8, // 抗菌
			24, -10, 8, // 耐震
			25, -10, 10, // 耐暑
			26, -10, 10, // 耐寒
			9, -7, 7, // 攻撃
			16, -7, 7, // 達人
			36, -4, 4, // 特殊攻撃
			78, -8, 8, // 爆弾強化
			76, -8, 8, // 笛
			77, -8, 8, // 砲術
			10, -7, 7, // 防御
			43, -10, 10, // 火耐性
			44, -10, 10, // 水耐性
			45, -10, 10, // 雷耐性
			46, -10, 10, // 氷耐性
			47, -10, 10, // 龍耐性
			11, -10, 10, // 体力
			12, -4, 4, // 回復速度
			101, -10, 10, // 高速設置
			82, -10, 10, // 腹減り
			83, -10, 13, // 食いしん坊
			98, -10, 10, // 運搬
			88, -10, 13, // 採取
			89, -10, 10, // 高速収集
			90, -10, 13, // 気まぐれ
			80, -10, 10, // 広域
			97, -10, 10, // 千里眼
			86, -10, 13, // 調合成功率
			87, -10, 10, // 調合数
			81, -10, 10, // 効果持続
			96, -10, 10, // 観察眼
			7, -10, 10, // こやし
			99, -10, 10, // 狩人
			32, -10, 10, // 気配
			62, -8, 8, // 通常弾追加
			63, -10, 10, // 貫通弾追加
			64, -10, 10, // 散弾追加
			65, -10, 10, // 榴弾追加
			66, -10, 10, // 拡散弾追加
			67, -10, 10, // 斬裂弾追加
			58, -10, 10, // 精密射撃
			70, -10, 10, // 麻痺瓶追加
			71, -10, 10, // 睡眠瓶追加
			69, -10, 10, // 毒瓶追加
			72, -10, 10, // 強撃瓶追加
			73, -10, 10, // 接撃瓶追加
			74, -10, 10, // 減気瓶追加
			102, -10, 10, // 燃鱗
			104, -10, 10, // 水流
			105, -10, 10, // 泳ぎ
			103, -10, 10, // 酸素
			115, -7, 7, // 采配
			116, -7, 7, // 号令
			75, -10, 10, // 爆破瓶追加
			68, -10, 10, // 爆破弾追加
		},

		//ancient
		{
			3, -10, 13, // 気絶
			22, -3, 3, // 聴覚保護
			23, -10, 3, // 風圧
			9, -10, 10, // 攻撃
			16, -10, 10, // 達人
			36, -10, 4, // 特殊攻撃
			37, -10, 9, // 火属性攻撃
			38, -10, 9, // 水属性攻撃
			39, -10, 9, // 雷属性攻撃
			40, -10, 9, // 氷属性攻撃
			41, -10, 9, // 龍属性攻撃
			17, -3, 3, // 痛撃
			18, -3, 3, // 重撃
			15, -3, 3, // 溜め短縮
			109, -3, 4, // 本気
			19, -3, 4, // KO
			20, -3, 4, // 減気攻撃
			107, -3, 4, // 底力
			78, -10, 10, // 爆弾強化
			76, -10, 10, // 笛
			77, -10, 10, // 砲術
			10, -10, 10, // 防御
			113, -3, 3, // 属性耐性
			43, -10, 13, // 火耐性
			44, -10, 13, // 水耐性
			45, -10, 13, // 雷耐性
			46, -10, 13, // 氷耐性
			47, -10, 13, // 龍耐性
			13, -10, 9, // 加護
			11, -10, 13, // 体力
			12, -10, 12, // 回復速度
			79, -3, 4, // 回復量
			29, -3, 4, // 回避性能
			30, -3, 4, // 回避距離
			14, -10, 4, // 納刀
			84, -3, 3, // 食事
			27, -3, 3, // スタミナ
			21, -3, 4, // 体術
			28, -3, 4, // 気力回復
			82, -10, 10, // 腹減り
			80, -10, 12, // 広域
			97, -10, 12, // 千里眼
			48, -3, 3, // 斬れ味
			33, -3, 4, // ガード性能
			34, -3, 4, // ガード強化
			51, -10, 8, // 研ぎ師
			59, -3, 3, // 通常弾強化
			60, -3, 3, // 貫通弾強化
			61, -3, 3, // 散弾強化
			54, -3, 4, // 装填速度
			57, -3, 3, // 反動
			102, -10, 13, // 燃鱗
			104, -10, 10, // 水流
			105, -10, 10, // 泳ぎ
			103, -10, 10, // 酸素
			115, -10, 10, // 采配
			116, -10, 10, // 号令
		},

		//weathered
		{
			3, -8, 11, // 気絶
			22, -1, 3, // 聴覚保護
			23, -8, 3, // 風圧
			9, -8, 10, // 攻撃
			16, -8, 10, // 達人
			36, -8, 4, // 特殊攻撃
			42, -3, 3, // 属性攻撃
			37, -8, 9, // 火属性攻撃
			38, -8, 9, // 水属性攻撃
			39, -8, 9, // 雷属性攻撃
			40, -8, 9, // 氷属性攻撃
			41, -8, 9, // 龍属性攻撃
			17, -1, 3, // 痛撃
			18, -1, 3, // 重撃
			55, -3, 3, // 装填数
			15, -1, 3, // 溜め短縮
			109, -1, 4, // 本気
			19, -1, 4, // KO
			20, -1, 4, // 減気攻撃
			107, -1, 4, // 底力
			78, -8, 10, // 爆弾強化
			76, -8, 10, // 笛
			77, -8, 10, // 砲術
			10, -8, 10, // 防御
			113, -1, 3, // 属性耐性
			43, -8, 11, // 火耐性
			44, -8, 11, // 水耐性
			45, -8, 11, // 雷耐性
			46, -8, 11, // 氷耐性
			47, -8, 11, // 龍耐性
			13, -8, 9, // 加護
			11, -8, 11, // 体力
			12, -8, 11, // 回復速度
			79, -1, 4, // 回復量
			29, -1, 4, // 回避性能
			30, -1, 4, // 回避距離
			14, -8, 4, // 納刀
			84, -1, 3, // 食事
			27, -1, 3, // スタミナ
			21, -1, 4, // 体術
			28, -1, 4, // 気力回復
			82, -8, 10, // 腹減り
			93, -3, 3, // 運気
			95, -3, 3, // 捕獲
			94, -3, 3, // 剥ぎ取り
			80, -8, 10, // 広域
			97, -8, 10, // 千里眼
			49, -3, 3, // 匠
			50, -3, 3, // 剣術
			48, -1, 3, // 斬れ味
			53, -3, 3, // 抜刀会心
			52, -3, 3, // 抜刀減気
			33, -1, 4, // ガード性能
			34, -1, 4, // ガード強化
			51, -8, 8, // 研ぎ師
			59, -1, 3, // 通常弾強化
			60, -1, 3, // 貫通弾強化
			61, -1, 3, // 散弾強化
			56, -3, 3, // 速射
			54, -1, 4, // 装填速度
			57, -1, 3, // 反動
			112, -5, 7, // 属性解放
			102, -8, 11, // 燃鱗
			104, -8, 10, // 水流
			105, -8, 10, // 泳ぎ
			103, -8, 10, // 酸素
			108, -3, 3, // 逆境
			85, -5, 5, // 肉食
			31, -5, 5, // 飛距離
			91, -5, 5, // ハチミツ
			8, -5, 5, // 細菌学
			110, -3, 3, // 闘魂
			111, -3, 3, // 無傷
			121, -3, 3, // 不動
			106, -3, 3, // 水の心
			114, -3, 3, // 根性
			119, -3, 3, // 刀匠
			120, -3, 3, // 射手
			117, -3, 3, // 状態耐性
			118, -3, 3, // 怒
			115, -8, 10, // 采配
			116, -8, 10, // 号令
			92, -8, 10, // 護石王
		},
	};
#pragma endregion
#pragma region Slot Table
	static array< array< unsigned char >^ >^ slot_table =
	{
		//mystery
		{
			70, 100, 100,
			75, 100, 100,
			80, 100, 100,
			85, 100, 100,
			90, 100, 100,
			92, 100, 100,
			95, 100, 100,
			99, 100, 100,
			100, 100, 100,
		},

		//shining =
		{
			50, 85, 100,
			58, 88, 100,
			65, 90, 100,
			72, 92, 100,
			79, 95, 100,
			83, 97, 100,
			86, 98, 100,
			89, 99, 100,
			91, 99, 100,
			95, 100, 100,
			97, 100, 100,
			99, 100, 100,
			99, 100, 100,
			100, 100, 100,
		},

		//ancient =
		{
			22, 72, 92,
			41, 76, 94,
			49, 79, 95,
			57, 82, 96,
			65, 85, 97,
			70, 88, 98,
			76, 91, 99,
			82, 94, 99,
			87, 97, 99,
			91, 99, 100,
			94, 99, 100,
			96, 99, 100,
			99, 100, 100,
			99, 100, 100,
			99, 100, 100,
			100, 100, 100,
		},

		//weathered =
		{
			22, 72, 92,
			41, 76, 96,
			48, 78, 96,
			59, 81, 97,
			63, 83, 97,
			6, 86, 98,
			76, 88, 98,
			76, 91, 99,
			84, 94, 99,
			88, 98, 100,
			90, 98, 100,
			93, 99, 100,
			97, 99, 100,
			98, 100, 100,
			99, 100, 100,
			99, 100, 100,
			100, 100, 100,
		},
	};
#pragma endregion
#pragma region Skill2Chance Table	
	static array< unsigned char >^ skill2_chance_table =
	{
		100,
		35,
		25,
		20
	};
#pragma endregion
};

int rnd( const int n )
{
	if( n == 0 ) return 176;

	int x = n * 16 - n * 4 - n;
	long long y = x * 16;
	long long z = y * 11367737L / 4294967296L;
	long long m = y - ( ( y - z ) / 2L + z ) / 32768L * 65363L;
	return (int)( m & 0xFFFF );
}

unsigned GetNumSlots( const unsigned charm_type, const int slot_table, const unsigned roll )
{
	const unsigned table_index = Math::Min( slot_table, StaticData::slot_table[ charm_type ]->Length / 3 ) - 1;
	const unsigned for2 = StaticData::slot_table[ charm_type ][ table_index * 3 + 1 ];
	const unsigned for3 = StaticData::slot_table[ charm_type ][ table_index * 3 + 2 ];
	const unsigned for1 = StaticData::slot_table[ charm_type ][ table_index * 3 + 0 ];
	return ( roll >= for2 )
		? ( ( roll >= for3 ) ? 3 : 2 )
		: ( ( roll >= for1 ) ? 1 : 0 );
}

unsigned HashFunction( const unsigned num_slots, const unsigned ab1_index, const int p1, unsigned ab2_index, const int p2, const unsigned charm_type, const unsigned table )
{
	//2 bits for slots
	//4 bits for point1
	//5 bits for point2
	//7 bits for ability1
	//7 bits for ability2
	//5 bits for table (non-standard)
	//2 bits for charm_type (non-standard)
	return num_slots + ( p1 << 2 ) + ( ( p2 + 12 ) << 6 ) + ( ab1_index << 11 ) + ( ab2_index << 18 ) + ( table << 25 ) + ( charm_type << 30 );
}

void GenerateCharm( const unsigned charm_type, const unsigned table, int n, const unsigned num )
{
	CharmDatum^ datum = gcnew CharmDatum();
	datum->seed = n;
	datum->num = num;
	//check charm_type < StaticData::skill1_table->Length
	array< unsigned char >^ skill1_table = StaticData::skill1_table[ charm_type ];
	const unsigned num_skills1 = skill1_table->Length / 3;
	//check charm_type < StaticData::skill2_table->Length
	array< signed char >^ skill2_table = StaticData::skill2_table[ charm_type ];
	const unsigned num_skills2 = skill2_table->Length / 3;

	//skill 1
	n = rnd( n );
	const int skill1_index = n % num_skills1;

	//skill 1 point
	n = rnd( n );
	const int skill1_name = skill1_table[ skill1_index * 3 ];
	const int skill1_min = skill1_table[ skill1_index * 3 + 1 ];
	const int skill1_max = skill1_table[ skill1_index * 3 + 2 ];
	const int point1 = skill1_min + n % ( skill1_max - skill1_min + 1 );

	//has skill 2?
	int skill2_index = -1, point2 = 0, skill2_min = 0, skill2_max = 0, skill2_name = 122;
	n = rnd( n );
	if( n % 100 >= StaticData::skill2_chance_table[ charm_type ] )
	{
		//skill 2
		n = rnd( n );
		skill2_index = n % num_skills2;
		skill2_name = skill2_table[ skill2_index * 3 ];
		skill2_min = skill2_table[ skill2_index * 3 + 1 ];
		skill2_max = skill2_table[ skill2_index * 3 + 2 ];

		//skill 2 point
		n = rnd( n );
		if( n % 2 == 1 ) //positive number
		{
			n = rnd( n );
			point2 = 1 + n % skill2_max;
		}
		else //negative number
		{
			n = rnd( n );
			point2 = skill2_min + n % ( 1 - skill2_min );
		}

		if( skill1_name == skill2_name || point2 == 0 )
		{
			skill2_min = skill2_max = point2 = 0;
			skill2_name = skill2_index = 122;
		}
	}

	const int slot_table = (int)Math::Floor( point1*10.0 / skill1_max + ( (point2 > 0) ? point2*10.0 / skill2_max : 0 ) );

	//slots
	n = rnd( n );
	const int num_slots = GetNumSlots( charm_type, slot_table, n % 100 );

	datum->hash = HashFunction( num_slots, skill1_name, point1, skill2_name, point2, charm_type, table );

	CharmDatabase::charm_hashes[ table ]->Add( datum );
	CharmDatabase::skill1_hashes[ table, skill1_name ]->Add( datum );
	if( skill2_name < 122 )
	{
		//if( skill2_name == 9 && point2 < 0 )
		//	System::Windows::Forms::MessageBox::Show( L"asdf" );
		CharmDatabase::skill1_hashes[ table, skill2_name ]->Add( datum );
		CharmDatabase::skill2_hashes[ table, skill1_name, skill2_name ]->Add( datum );
	}
}

int CompareCharms( CharmDatum^ ah, CharmDatum^ bh )
{
#define Compare(X) { const int av = GetCharm##X(ah->hash), bv = GetCharm##X(bh->hash); if( av != bv ) return av - bv; }
	Compare(Ability1Index);
	Compare(Ability1Points);
	Compare(Ability2Index);
	Compare(Ability2Points);
	Compare(Slots);
	return 0;
#undef Compare
}

unsigned GetFishIndex( const unsigned roll, array< unsigned >^ fish )
{
	unsigned total = fish[ 0 ], count = 0;
	while( total <= roll )
	{
		total += fish[ ++count ];
	}
	return count;
}

enum FishRewards
{
	ShiningStarfishx1 = 0,
	PinTunax2 = 1,
	ShiningStarfishx2 = 2,
	Sushifishx2 = 3,
	Popfishx5 = 4,
	Sushifishx3 = 5,
	Whetfishx6 = 6,
	Sleepyfishx2 = 7,
	Popfishx4 = 8,
	Whetfishx4 = 9,
	HumspunConch = 10,
};

unsigned reward_func( unsigned num, const unsigned rep )
{
	for( unsigned i = 0; i < rep; ++i )
		num = ( num * 176 ) % 65363;
	return num;
}

bool SearchSeed( const unsigned seed, const bool fishfinder, array< unsigned >^ fish_table, array< unsigned >^ items )
{
	const int min_fish = fishfinder ? 6 : 3;
	System::Collections::Generic::List< unsigned > escapes;
	unsigned j = 0;
	unsigned qwe[20];
	for( ; j < 20; )
	{
		const unsigned roll = reward_func( seed, ++j ) % 100;
		//escapes.Add( GetFishIndex( roll, fish_table ) );
		qwe[j-1] = GetFishIndex( roll, fish_table );
	}
	

	j = 0;
	unsigned fails = 0;
	for( int i = 0; i < items->Length-5; ++i )
	{
		const unsigned roll = reward_func( seed, ++j ) % 100;
		const unsigned count = GetFishIndex( roll, fish_table );

		//if( i >= 5 )
		//	++j;//escapes.Add( reward_func( seed, ++j ) );

		if( count != items[ i ] && ++fails > 1 )
			return false;
	}
	/*j += 4;
	if( fishfinder )
	{
		const unsigned extra = 3;
		for( unsigned i = 0; i < extra; ++i )
		{
			const unsigned roll = reward_func( seed, ++j ) % 100;
			const unsigned count = GetFishIndex( roll, fish_table );
			if( count != items[ items->Length - 3 + i ] )
				return false;
		}
	}*/
	return true;
}

unsigned CheckSeed( const int seed, const bool fishfinder, array< unsigned >^ fish_table, array< unsigned >^ items )
{
	unsigned total = 0;
	int n = seed;
	do
	{
		if( SearchSeed( n, fishfinder, fish_table, items ) )
			total++;

		n = rnd( n );
	}
	while( n != seed );
	return total;
}

void GenerateCharmTable()
{
	array< int >^ table_seeds = { 1, 15, 5, 13, 4, 3, 9, 12, 26, 18, 163, 401, 6, 2, 489, 802, 1203 };
	/*array< unsigned >^ table_works1 = gcnew array< unsigned >( table_seeds->Length );
	array< unsigned >^ table_works2 = gcnew array< unsigned >( table_seeds->Length );
	array< unsigned >^ table_works3 = gcnew array< unsigned >( table_seeds->Length );
	array< unsigned >^ table_works4 = gcnew array< unsigned >( table_seeds->Length );
	array< unsigned >^ table_works5 = gcnew array< unsigned >( table_seeds->Length );
	array< unsigned >^ table_works6 = gcnew array< unsigned >( table_seeds->Length );
	array< unsigned >^ table_works7 = gcnew array< unsigned >( table_seeds->Length );
	array< unsigned >^ table_works8 = gcnew array< unsigned >( table_seeds->Length );
	array< unsigned >^ table_works9 = gcnew array< unsigned >( table_seeds->Length );
	array< unsigned >^ fish = { 20, 15, 5, 5, 10, 15, 5, 10, 5, 5, 5 };
	//table 5
	array< unsigned >^ items1 = { Sushifishx3, HumspunConch, Sleepyfishx2, PinTunax2, Sushifishx3, Whetfishx4, PinTunax2 };
	array< unsigned >^ items2 = { ShiningStarfishx1, ShiningStarfishx1, ShiningStarfishx1, Sleepyfishx2, PinTunax2, Whetfishx6, Popfishx4 };
	array< unsigned >^ items3 = { PinTunax2, ShiningStarfishx1, Sushifishx2, Sushifishx2, ShiningStarfishx2, Sleepyfishx2, HumspunConch };
	array< unsigned >^ items4 = { Popfishx4, ShiningStarfishx1, Sushifishx3, Whetfishx4, Popfishx4, ShiningStarfishx1, ShiningStarfishx1, Sushifishx3 };
	array< unsigned >^ items5 = { Popfishx4, ShiningStarfishx1, ShiningStarfishx1, Whetfishx4, Sushifishx3, Sleepyfishx2, Sleepyfishx2 };
	array< unsigned >^ items6 = { ShiningStarfishx2, ShiningStarfishx1, PinTunax2, Sushifishx2, Whetfishx6, HumspunConch, Popfishx5 };
	array< unsigned >^ items7 = { Sushifishx2, ShiningStarfishx2, Sushifishx2, ShiningStarfishx2, Sushifishx2, Popfishx5, Sushifishx3 };
	array< unsigned >^ items8 = { Sleepyfishx2, Popfishx5, PinTunax2, Sushifishx3, Sushifishx3, Sushifishx3 };
	array< unsigned >^ items9 = { Popfishx5, PinTunax2, Popfishx4, Sleepyfishx2 };
	array< unsigned >^ items10 ={ ShiningStarfishx2, PinTunax2, ShiningStarfishx1, Whetfishx6 };
	//table 10
	array< unsigned >^ items11 = { Popfishx5, Sleepyfishx2, Sushifishx3, PinTunax2, Whetfishx4, Sushifishx3, ShiningStarfishx1, Popfishx4 };
	array< unsigned >^ items13 = { ShiningStarfishx1, Popfishx4, Popfishx5, PinTunax2, Whetfishx6 };
	array< unsigned >^ items14 = { Sleepyfishx2, Sleepyfishx2, Popfishx4, ShiningStarfishx1, Whetfishx6 };
	array< unsigned >^ items16 = { ShiningStarfishx1, Popfishx5, PinTunax2, Sushifishx3, PinTunax2, Sushifishx3, Sushifishx2, Sushifishx3 };
	array< unsigned >^ items17 = { Popfishx4, PinTunax2, PinTunax2, ShiningStarfishx1, Whetfishx6, Sleepyfishx2, Sleepyfishx2, Sushifishx3 };
	//table 7
	array< unsigned >^ items12 = { ShiningStarfishx2, Sushifishx3, ShiningStarfishx1, ShiningStarfishx1, PinTunax2, Whetfishx6, Sushifishx2, Sushifishx3, Sushifishx3 };
	//table 6
	array< unsigned >^ items15 = { ShiningStarfishx2, Sushifishx3, ShiningStarfishx1, Sleepyfishx2, PinTunax2, ShiningStarfishx1 };

	for( int t = 4; t < table_seeds->Length; ++t )
	{
		
		break;
	}
	//CheckSeed( table_seeds[9], false, fish, items14 );
	//table_works1[4] = CheckSeed( table_seeds[t], true, fish, items2 );
	//table_works4[4] = CheckSeed( table_seeds[4], true, fish, items4 );
	//table_works5[4] = CheckSeed( table_seeds[4], true, fish, items5 );
	//table_works8[4] = CheckSeed( table_seeds[4], false, fish, items10 );
	CheckSeed( table_seeds[9], true, fish, items17 );*/


	//setup databases
	CharmDatabase::charm_hashes = gcnew array< System::Collections::Generic::List< CharmDatum^ >^ >( 17 );
	CharmDatabase::skill1_hashes = gcnew array< System::Collections::Generic::List< CharmDatum^ >^, 2 >( 17, 122 );
	CharmDatabase::skill2_hashes = gcnew array< System::Collections::Generic::List< CharmDatum^ >^, 3 >( 17, 122, 122 );

	Comparison< CharmDatum^ >^ comparer = gcnew Comparison< CharmDatum^ >( CompareCharms );
	
	//generate charms
	for( int t = 0; t < table_seeds->Length; ++t )
	{
		CharmDatabase::charm_hashes[ t ] = gcnew System::Collections::Generic::List< CharmDatum^ >();
		for( unsigned i = 0; i < 122; ++i )
		{
			CharmDatabase::skill1_hashes[ t, i ] = gcnew System::Collections::Generic::List< CharmDatum^ >();
			for( unsigned j = i + 1; j < 122; ++j )
			{
				CharmDatabase::skill2_hashes[ t, i, j ] = gcnew System::Collections::Generic::List< CharmDatum^ >();
				CharmDatabase::skill2_hashes[ t, j, i ] = CharmDatabase::skill2_hashes[ t, i, j ];
			}
		}

		for( int charm_type = 0; charm_type < StaticData::slot_table->Length; ++charm_type )
		{
			unsigned total = 0;
			int n = table_seeds[ t ];
			do
			{
				GenerateCharm( charm_type, t, n, total++ );
				n = rnd( n );
			}
			while( n != table_seeds[ t ] );
		}

		//sort charms
		CharmDatabase::charm_hashes[ t ]->Sort( comparer );
		for( unsigned i = 0; i < 122; ++i )
		{
			CharmDatabase::skill1_hashes[ t, i ]->Sort( comparer );
			for( unsigned j = i + 1; j < 122; ++j )
				CharmDatabase::skill2_hashes[ t, i, j ]->Sort( comparer );
		}
	}

	CharmDatabase::ability_names = gcnew array< String^ >( 122 );
}

unsigned GetCharmSlots( const unsigned charm_hash )
{
	return charm_hash & 0x3;
}

unsigned GetCharmAbility1Index( const unsigned charm_hash )
{
	return ( charm_hash >> 11 ) & 0x7F;
}

unsigned GetCharmAbility2Index( const unsigned charm_hash )
{
	return ( charm_hash >> 18 ) & 0x7F;
}

unsigned GetCharmAbility1Points( const unsigned charm_hash )
{
	return ( charm_hash >> 2 ) & 0xF;
}

int GetCharmAbility2Points( const unsigned charm_hash )
{
	return ( ( charm_hash >> 6 ) & 0x1F ) - 12;
}

unsigned GetCharmType( const unsigned charm_hash )
{
	return charm_hash >> 30;
}

unsigned GetCharmTable( const unsigned charm_hash )
{
	return ( charm_hash >> 25 ) & 0x1F;
}