#pragma once
#include <wut.h>

/**
 * \defgroup nn_ffl_miidata Mii binary format
 * \ingroup nn_ffl
 * Binary format for Mii storage and exchange
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

// https://github.com/decaf-emu/decaf-emu/blob/master/src/libdecaf/src/nn/ffl/nn_ffl_miidata.h

typedef enum FFLCreateIDFlags {
   FFL_CREATE_ID_FLAG_WII_U    = 0x1 | 0x4,
   FFL_CREATE_ID_FLAG_TEMPORARY = 0x2,
   FFL_CREATE_ID_FLAG_NORMAL   = 0x8,
} FFLCreateIDFlags;

typedef struct WUT_PACKED FFLCreateID {
   FFLCreateIDFlags flags : 4;

   uint32_t timestamp : 28;

   uint8_t deviceHash[6];
} FFLCreateID;
WUT_CHECK_OFFSET(FFLCreateID, 4, deviceHash);
WUT_CHECK_SIZE(FFLCreateID, 10);


typedef struct WUT_PACKED FFLiMiiDataCore {
   //! From ffl/include/nn/ffl/FFLiMiiDataCore.h
   union
    {
        struct
        {
            uint32_t                 : 1;    // Unused (MSB)
            //! The platform the Mii was made on
            uint32_t m_BirthPlatform : 3;
            uint32_t _0_24_27        : 4;

            //! The Mii's slot index in Mii Maker
            uint32_t m_SlotIndex     : 4;
            //! The Mii's page index in Mii Maker
            uint32_t m_PageIndex     : 4;

            uint32_t                 : 2;    // Unused
            //! The font file for the system to use with this Mii.
            uint32_t m_FontRegion    : 2;
            //! The region lock imposed on the Mii.
            uint32_t m_RegionMove    : 2;
            //! Whether the Mii's name or creator name contains profanity (to censor out)
            uint32_t m_NgWord        : 1;    // bool
            //! Whether the Mii is copyable
            uint32_t m_Copyable      : 1;    // bool
            //! The Mii's version
            uint32_t m_MiiVersion    : 8;    // (LSB)
        };

        uint32_t _0;
    };

    union
    {
        FFLiAuthorID    m_AuthorID;

        uint8_t  _4[8];
    };

    union
    {
        FFLCreateID m_CreatorID;

        uint8_t  _c[0xA];
    };
    uint8_t  _padding1[2];

    union
    {
        struct
        {
            uint16_t m_PlaceHolder   : 1;    // Unused (MSB)
            //! Whether the Mii is favorited in Mii Maker
            uint16_t m_FavoriteMii   : 1;    // bool
            //! The Mii's shirt color
            uint16_t m_FavoriteColor : 4;
            //! The Mii's birthday day
            uint16_t m_BirthDay      : 5;
            //! The Mii's birthday month
            uint16_t m_BirthMonth    : 4;
            //! The Mii's gender
            uint16_t m_Gender        : 1;    // (LSB)
        };

        uint16_t _18;
    };

    uint16_t m_Name[10]; // Wstring

    uint8_t  m_Height;
    uint8_t  m_Build;

    union
    {
        struct
        {
            //! The Mii's makeup
            uint16_t m_FaceMakeup    : 4;    // (MSB)
            uint16_t m_FaceLine      : 4;
            //! The Mii's skin color
            uint16_t m_FacelineColor : 3;
            //! The Mii's facial structure
            uint16_t m_FaceType      : 4;
            //! Whether the Mii is local only
            uint16_t m_LocalOnly     : 1;    // bool (LSB)
        };

        uint16_t _30;
    };
    union
    {
        struct
        {
            uint16_t             : 4;    // Unused (MSB)
            //! If the hair is flipped
            uint16_t m_HairDir   : 1;
            //! The color of the Mii's hair
            uint16_t m_HairColor : 3;
            //! The Mii's hair style
            uint16_t m_HairType  : 8;    // (LSB)
        };

        uint16_t _32;
    };
    union
    {
        struct
        {
            //! The y stretch scale of the Mii's eyes
            uint16_t m_EyeScaleY : 3;    // (MSB)
            //! The x stretch scale of the Mii's eyes
            uint16_t m_EyeScale  : 4;
            //! The color of the Mii's eyes
            uint16_t m_EyeColor  : 3;
            //! The type of eyes the Mii has
            uint16_t m_EyeType   : 6;    // (LSB)
        };

        uint16_t _34;
    };
    union
    {
        struct
        {
            uint16_t                     : 2;    // Unused (MSB)
            //! The vertical placement of the Mii's eyes on its face
            uint16_t m_EyePositionY      : 5;
            //! The spacing between the Mii's eyes
            uint16_t m_EyeSpacingX       : 4;
            //! The rotation of the Mii's eyes
            uint16_t m_EyeRotate         : 5;    // (LSB)
        };

        uint16_t _36;
    };
    union
    {
        struct
        {
            uint16_t                 : 1;    // Unused (MSB)
            //! The vertical thickness of the Mii's eyebrows
            uint16_t m_EyebrowScaleY : 3;
            //! The horizontal thickness of the Mii's eyebrows
            uint16_t m_EyebrowScale  : 4;
            //! The color of the Mii's eyebrows
            uint16_t m_EyebrowColor  : 3;
            //! The style of the Mii's eyebrows
            uint16_t m_EyebrowType   : 5;    // (LSB)
        };

        uint16_t _38;
    };
    union
    {
        struct
        {
            uint16_t                         : 2;    // Unused (MSB)
            //! The vertical placement of the eyebrows on the Mii's face
            uint16_t m_EyebrowPositionY      : 5;
            //! The spacing between the Mii's eyebrows
            uint16_t m_EyebrowSpacingX       : 4;
            //! The rotation of the Mii's eyebrows
            uint16_t m_EyebrowRotate         : 5;    // (LSB)
        };

        uint16_t _3A;
    };
    union
    {
        struct
        {
            uint16_t                 : 2;    // Unused (MSB)
            //! The vertical placement of the Mii's nose
            uint16_t m_NosePositionY : 5;
            //! The size of the Mii's nose
            uint16_t m_NoseScale     : 4;
            //! The shape of the Mii's nose
            uint16_t m_NoseType      : 5;    // (LSB)
        };

        uint16_t _3C;
    };
    union
    {
        struct
        {
            //! The vertical scale of the Mii's mouth
            uint16_t m_MouthScaleY   : 3;    // (MSB)
            //! The horizontal scale of the Mii's mouth
            uint16_t m_MouthScale    : 4;
            //! The color of the Mii's lips (for types that have colors)
            uint16_t m_MouthColor    : 3;
            //! The mouth type of the Mii
            uint16_t m_MouthType     : 6;    // (LSB)
        };

        uint16_t _3E;
    };
    union
    {
        struct
        {
            uint16_t                     : 8;    // Unused (MSB)
            //! The type of mustache the Mii has
            uint16_t m_MustacheType      : 3;
            //! The vertical placement of the Mii's mouth
            uint16_t m_MouthPositionY    : 5;    // (LSB)
        };

        uint16_t _40;
    };
    union
    {
        struct
        {
            uint16_t                     : 1;    // Unused (MSB)
            //! The vertical position of the Mii's mustache
            uint16_t m_MustachePositionY : 5;
            //! The size of the Mii's mustache
            uint16_t m_MustacheScale     : 4;
            //! The color of the Mii's beard
            uint16_t m_BeardColor        : 3;
            //! The type of beard the Mii has
            uint16_t m_BeardType         : 3;    // (LSB)
        };

        uint16_t _42;
    };
    union
    {
        struct
        {
            //! The vertical position of the Mii's glasses
            uint16_t m_GlassPositionY    : 5;    // (MSB)
            //! The size of the Mii's glasses
            uint16_t m_GlassScale        : 4;
            //! The color of the Mii's glasses
            uint16_t m_GlassColor        : 3;
            //! The type of glasses the Mii has
            uint16_t m_GlassType         : 4;    // (LSB)
        };

        uint16_t _44;
    };
    union
    {
        struct
        {
            uint16_t                 : 1;    // Unused (MSB)
            //! The vertical position of the Mii's mole
            uint16_t m_MolePositionY : 5;
            //! The horizontal position of the Mii's mole
            uint16_t m_MolePositionX : 5;
            //! The size of the Mii's mole
            uint16_t m_MoleScale     : 4;
            //! Whether or not the Mii's mole is visible
            uint16_t m_MoleType      : 1;    // (LSB)
        };

        uint16_t _46;
} FFLiMiiDataCore;
//Idk how to adapt these to the original FFL code. when in doubt, comment out, I guess
//WUT_CHECK_OFFSET(FFLiMiiDataCore, 0x03, mii_version);
//WUT_CHECK_OFFSET(FFLiMiiDataCore, 0x04, author_id);
//WUT_CHECK_OFFSET(FFLiMiiDataCore, 0x0C, mii_id);
//WUT_CHECK_OFFSET(FFLiMiiDataCore, 0x16, unk_0x16);
//WUT_CHECK_OFFSET(FFLiMiiDataCore, 0x1A, mii_name);
//WUT_CHECK_OFFSET(FFLiMiiDataCore, 0x2E, size);
//WUT_CHECK_OFFSET(FFLiMiiDataCore, 0x2F, m_Build);
//WUT_CHECK_OFFSET(FFLiMiiDataCore, 0x33, hair_type);
WUT_CHECK_SIZE(FFLiMiiDataCore, 0x48);

typedef struct WUT_PACKED FFLiMiiDataOfficial {
   FFLiMiiDataCore core;
   uint16_t creator_name[10];
} FFLiMiiDataOfficial;
WUT_CHECK_OFFSET(FFLiMiiDataOfficial, 0x48, creator_name);
WUT_CHECK_SIZE(FFLiMiiDataOfficial, 0x5C);

typedef struct WUT_PACKED FFLStoreData {
   FFLiMiiDataOfficial data;
   uint16_t unk_0x5C;
   uint16_t checksum;
} FFLStoreData;
WUT_CHECK_OFFSET(FFLStoreData, 0x5C, unk_0x5C);
WUT_CHECK_OFFSET(FFLStoreData, 0x5E, checksum);
WUT_CHECK_SIZE(FFLStoreData, 0x60);

#ifdef __cplusplus
}
#endif

/** @} */
