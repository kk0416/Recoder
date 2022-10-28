/*
 Navicat Premium Data Transfer

 Source Server         : recoder1
 Source Server Type    : SQLite
 Source Server Version : 3030001
 Source Schema         : main

 Target Server Type    : SQLite
 Target Server Version : 3030001
 File Encoding         : 65001

 Date: 25/02/2022 17:06:12
*/

PRAGMA foreign_keys = false;

-- ----------------------------
-- Table structure for tbl_device
-- ----------------------------
DROP TABLE IF EXISTS "tbl_device";
CREATE TABLE "tbl_device" (
  "dvid" text(6) NOT NULL,
  "dvmodel" text(10) NOT NULL,
  "dvname" text(10),
  PRIMARY KEY ("dvid")
);

-- ----------------------------
-- Records of tbl_device
-- ----------------------------
INSERT INTO "tbl_device" VALUES ('HY-2022-001', 1001, '设备1');
INSERT INTO "tbl_device" VALUES ('HY-2022-002', 1002, '设备2');
INSERT INTO "tbl_device" VALUES ('HY-2022-003', 1003, '设备3');

-- ----------------------------
-- Table structure for tbl_log
-- ----------------------------
DROP TABLE IF EXISTS "tbl_log";
CREATE TABLE "tbl_log" (
  "logid" INTEGER(6) NOT NULL,
  "logTime" text(110) NOT NULL,
  "dvId" text(20) DEFAULT NULL,
  "userID" text(20) DEFAULT NULL,
  "operType" text(255) DEFAULT NULL,
  PRIMARY KEY ("logid")
);

-- ----------------------------
-- Records of tbl_log
-- ----------------------------
INSERT INTO "tbl_log" VALUES (2001, 1, 'HY-2022-001', 11, NULL);

-- ----------------------------
-- Table structure for tbl_photo
-- ----------------------------
DROP TABLE IF EXISTS "tbl_photo";
CREATE TABLE "tbl_photo" (
  "ptId" integer(11) NOT NULL,
  "ptName" varchar(255) DEFAULT NULL,
  "ptType" integer(255) DEFAULT NULL,
  "ptTime" text DEFAULT NULL,
  "ptPath" text(255) DEFAULT NULL,
  "userID" text(11) DEFAULT NULL,
  PRIMARY KEY ("ptId")
);

-- ----------------------------
-- Records of tbl_photo
-- ----------------------------
INSERT INTO "tbl_photo" VALUES (1, 'Pic_02-25-14-48-02.jpg', NULL, '周五 2月 25 14:48:02 2022', './picturpath', NULL);
INSERT INTO "tbl_photo" VALUES (2, 'Pic_02-25-14-48-12.jpg', NULL, '周五 2月 25 14:48:12 2022', './picturpath', NULL);
INSERT INTO "tbl_photo" VALUES (3, 'Pic_02-25-14-48-14.jpg', NULL, '周五 2月 25 14:48:14 2022', './picturpath', NULL);
INSERT INTO "tbl_photo" VALUES (4, 'Pic_02-25-14-48-17.jpg', NULL, '周五 2月 25 14:48:17 2022', './picturpath', NULL);
INSERT INTO "tbl_photo" VALUES (5, 'Pic_02-25-14-52-09.jpg', NULL, '周五 2月 25 14:52:09 2022', './picturpath', NULL);

-- ----------------------------
-- Table structure for tbl_user
-- ----------------------------
DROP TABLE IF EXISTS "tbl_user";
CREATE TABLE "tbl_user" (
  "userId" text(11) NOT NULL,
  "userName" varchar(255) DEFAULT NULL,
  "userPwd" varchar(255) DEFAULT NULL,
  "userState" int(255) DEFAULT NULL,
  "uLoginTime" text(30),
  "uRgsTime" text(30),
  PRIMARY KEY ("userId")
);

-- ----------------------------
-- Records of tbl_user
-- ----------------------------
INSERT INTO "tbl_user" VALUES (11, 111111, 111111, 1, NULL, NULL);
INSERT INTO "tbl_user" VALUES (22, 222222, 222222, 1, NULL, NULL);
INSERT INTO "tbl_user" VALUES (33, 333333, 333333, 1, NULL, NULL);
INSERT INTO "tbl_user" VALUES (44, 444444, 444444, NULL, NULL, NULL);
INSERT INTO "tbl_user" VALUES (55, 555555, 555555, NULL, NULL, NULL);
INSERT INTO "tbl_user" VALUES (66, 666666, 666666, NULL, NULL, NULL);
INSERT INTO "tbl_user" VALUES (777777, 777777, 777777, NULL, NULL, NULL);
INSERT INTO "tbl_user" VALUES (888, 888, 888, NULL, NULL, NULL);

-- ----------------------------
-- Table structure for tbl_video
-- ----------------------------
DROP TABLE IF EXISTS "tbl_video";
CREATE TABLE "tbl_video" (
  "vdId" int(20) NOT NULL,
  "vdName" varchar(255) DEFAULT NULL,
  "userID" text(20) NOT NULL,
  "vdType" varchar(255) DEFAULT NULL,
  "vdTime" datetime(255) DEFAULT NULL,
  "vdPath" varchar(255) DEFAULT NULL,
  "coverPath" varchar(255) DEFAULT NULL,
  PRIMARY KEY ("vdId")
);

-- ----------------------------
-- Records of tbl_video
-- ----------------------------

PRAGMA foreign_keys = true;
