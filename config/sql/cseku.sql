-- phpMyAdmin SQL Dump
-- version 4.8.4
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1:3306
-- Generation Time: Jul 18, 2019 at 06:41 AM
-- Server version: 5.7.24
-- PHP Version: 7.2.14

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `cseku`
--

-- --------------------------------------------------------

--
-- Table structure for table `ams_asset`
--

DROP TABLE IF EXISTS `ams_asset`;
CREATE TABLE IF NOT EXISTS `ams_asset` (
  `id` varchar(40) NOT NULL,
  `type_id` int(11) NOT NULL,
  `serialNo` varchar(256) NOT NULL,
  `modelNo` varchar(256) NOT NULL,
  `brand` varchar(256) NOT NULL,
  `purchaseDate` date NOT NULL,
  `status` varchar(256) NOT NULL,
  `configuration` text NOT NULL,
  `stuff_id` varchar(40) NOT NULL,
  `purchasedFrom` varchar(256) NOT NULL,
  `cost` double NOT NULL,
  `warrantyLimit` date NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `serialNo` (`serialNo`),
  KEY `type_id` (`type_id`),
  KEY `user_id` (`stuff_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `ams_asset_type`
--

DROP TABLE IF EXISTS `ams_asset_type`;
CREATE TABLE IF NOT EXISTS `ams_asset_type` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(256) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `ams_repair`
--

DROP TABLE IF EXISTS `ams_repair`;
CREATE TABLE IF NOT EXISTS `ams_repair` (
  `id` varchar(40) NOT NULL,
  `asset_id` varchar(40) NOT NULL,
  `problem` text NOT NULL,
  `sendingDate` date NOT NULL,
  `receivingDate` date DEFAULT NULL,
  `status` varchar(256) DEFAULT NULL,
  `sent_by` varchar(40) NOT NULL,
  `received_by` varchar(40) DEFAULT NULL,
  `repaired_from` varchar(256) NOT NULL,
  `cost` double DEFAULT NULL,
  `onWarranty` tinyint(1) NOT NULL,
  `isReceived` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  KEY `sent_by` (`sent_by`),
  KEY `received_by` (`received_by`),
  KEY `asset_id` (`asset_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `ams_user_asset`
--

DROP TABLE IF EXISTS `ams_user_asset`;
CREATE TABLE IF NOT EXISTS `ams_user_asset` (
  `id` varchar(40) NOT NULL,
  `user_id` varchar(40) NOT NULL,
  `asset_id` varchar(40) NOT NULL,
  `lendingDate` date NOT NULL,
  PRIMARY KEY (`id`),
  KEY `user_id` (`user_id`),
  KEY `asset_id` (`asset_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `blood`
--

DROP TABLE IF EXISTS `blood`;
CREATE TABLE IF NOT EXISTS `blood` (
  `bloodID` int(11) NOT NULL AUTO_INCREMENT,
  `userID` varchar(40) DEFAULT NULL,
  `expire_date` date DEFAULT NULL,
  `blood_donate_date` date DEFAULT NULL,
  PRIMARY KEY (`bloodID`)
) ENGINE=MyISAM AUTO_INCREMENT=35 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `blood`
--

INSERT INTO `blood` (`bloodID`, `userID`, `expire_date`, `blood_donate_date`) VALUES
(25, 'monir150227@gmail.com', '2019-01-24', '2018-10-26'),
(21, 'monir150227@gmail.com', '2018-09-11', '2018-06-13'),
(20, 'monir150227@gmail.com', '2018-09-10', '2018-06-12'),
(23, 'monir150227@gmail.com', '2019-01-23', '2018-10-25'),
(26, 'mehadi.cse16@gmail.com', '2018-09-12', '2018-06-14'),
(27, 'mehadi.cse16@gmail.com', '2019-01-24', '2018-10-26'),
(28, 'mkazi078@uottawa.ca', '2019-01-25', '2018-10-27'),
(29, 'abir@gmail.com', '2018-10-02', '2018-07-04'),
(30, 'abir@gmail.com', '2018-01-26', '2017-10-28'),
(31, 'naim16@gmail.com', '2010-10-13', '2010-07-15'),
(32, 'naim16@gmail.com', '2019-01-27', '2018-10-29'),
(33, 'mefahimrahman@gmail.com', '2019-07-09', '2019-04-10'),
(34, 'mkazi078@uottawa.ca', '2019-07-14', '2019-04-15');

-- --------------------------------------------------------

--
-- Table structure for table `bsms_book`
--

DROP TABLE IF EXISTS `bsms_book`;
CREATE TABLE IF NOT EXISTS `bsms_book` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `user_name` varchar(1000) NOT NULL,
  `name` varchar(1000) NOT NULL,
  `edition` varchar(1000) NOT NULL,
  `writter` varchar(1000) NOT NULL,
  `description` varchar(1000) NOT NULL,
  `user_id` varchar(20) NOT NULL,
  `ammount` double NOT NULL,
  `contact_number` varchar(11) NOT NULL,
  `date` date NOT NULL,
  `img_name` varchar(1000) NOT NULL,
  `img` longblob NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=17 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `bsms_book`
--

INSERT INTO `bsms_book` (`id`, `user_name`, `name`, `edition`, `writter`, `description`, `user_id`, `ammount`, `contact_number`, `date`, `img_name`, `img`) VALUES
(1, 'Aysha  Akther', 'House Of Dead', '2nd', 'Mrittunjoy Gain', 'Normal', 'aysha@gmail.com', 120, '01521323232', '2018-09-28', '', ''),
(2, 'Aysha  Akther', 'Mathematical Method', '1st', 'Mrittunjoy Gain', 'Total new. Just read once.', 'aysha@gmail.com', 330, '01711548789', '2018-09-28', '', ''),
(15, 'Aysha  Akther', 'Debi', '6th', 'humayan Ahmed', 'New', 'aysha@gmail.com', 500, '01521369845', '2018-10-29', '', ''),
(5, 'Kashif Nizam  Khan', 'Math', '2nd', 'Wizz Jenson', 'New', 'kashif@gmail.com', 80, '01925865642', '2018-10-02', '', ''),
(6, 'Kashif Nizam  Khan', 'American Pie', '2nd', 'Robert Willson', 'Total new. Just read once.', 'kashif@gmail.com', 380, '01711456525', '2018-10-02', '', ''),
(9, 'Zahidul  Islam', 'House Of Dead', '2nd', 'Mrittunjoy Gain', 'Normal', 'zahid@gmail.com', 480, '01838562634', '2018-10-02', '', ''),
(11, 'Zahidul  Islam', 'The Amazing Spider-Man', '1st', 'Antor Ali', 'Used for 6 months', 'zahid@gmail.com', 350, '01521323232', '2018-10-10', '', ''),
(13, 'Kashif Nizam  Khan', 'Dead Pool', '2nd', 'Anam Bravo', 'New', 'kashif@gmail.com', 200, '01521369845', '2018-10-23', '', ''),
(14, 'Kashif Nizam  Khan', 'Dead Man', '2nd', 'Anon Ajax', 'Good', 'kashif@gmail.com', 120, '01711485269', '2018-10-23', '', '');

-- --------------------------------------------------------

--
-- Table structure for table `budget_sector`
--

DROP TABLE IF EXISTS `budget_sector`;
CREATE TABLE IF NOT EXISTS `budget_sector` (
  `budget_sector_id` int(11) NOT NULL,
  `budget_sector_name` varchar(50) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `budget_sector`
--

INSERT INTO `budget_sector` (`budget_sector_id`, `budget_sector_name`) VALUES
(41, 'Mosque'),
(40, 'Sports Section'),
(39, 'Academic Building Development'),
(38, 'Teacher Salary'),
(37, 'Organization'),
(36, 'Transport'),
(34, 'Pharmacy'),
(53, 'Library'),
(42, 'Study Instruments'),
(43, 'Saminer');

-- --------------------------------------------------------

--
-- Table structure for table `budget_subsector`
--

DROP TABLE IF EXISTS `budget_subsector`;
CREATE TABLE IF NOT EXISTS `budget_subsector` (
  `budget_subsector_id` int(11) NOT NULL,
  `budget_sector_id` int(11) NOT NULL,
  `start_date` date NOT NULL,
  `end_date` date NOT NULL,
  `budget_progress` varchar(20) NOT NULL,
  `description` text NOT NULL,
  `amount` double NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `budget_subsector`
--

INSERT INTO `budget_subsector` (`budget_subsector_id`, `budget_sector_id`, `start_date`, `end_date`, `budget_progress`, `description`, `amount`) VALUES
(9, 31, '2018-10-16', '2018-10-23', '33', 'dsdsaad', 0),
(8, 31, '2018-10-16', '2018-10-23', '33', 'dsdsaad', 0),
(7, 30, '2018-10-02', '2018-10-04', '44', 'ssssssssssss', 0),
(6, 29, '2018-10-10', '2018-10-25', '78', 'fnbfg', 0),
(10, 32, '2018-10-01', '2018-10-31', '10', 'description', 10000),
(11, 32, '2018-10-01', '2018-10-31', '15', 'Description', 210000),
(12, 41, '2015-06-15', '2020-02-03', '90', '							This is the Budget of University mosque.Contraction almost 70 parcent complete.probably mosque construction will done a few month.						', 500000),
(13, 40, '2018-10-02', '2019-06-17', '55', 'This the sports section.every year contribute 50,000 amount in section.', 50000),
(17, 39, '2018-10-01', '2019-01-01', '45', 'This is the Section of Academic building contraction of university.Every year allotment of amount.', 200000),
(18, 38, '2018-10-01', '2019-10-01', '100', 'This is the Sector of Teacher Salry.Every year contribute to admisastration.', 600000),
(19, 37, '2018-10-01', '2019-10-01', '100', 'This is the cultural section.Every year organize various cultural event Such that Rag Day,Pitha Uthsob,Pohela Boishak etc.\r\nAt the beginning of the year.Is determined ammount.', 500000),
(20, 35, '2018-10-01', '2020-10-04', '67', 'uu', 50000),
(21, 35, '2018-10-03', '2018-10-04', '49', 'ffff', 555555),
(22, 53, '2018-02-02', '2014-11-01', '66', '							This Is the Library unit.						', 10000),
(23, 53, '2018-02-02', '2014-11-01', '88', 'This Is the Library unit.', 10000);

-- --------------------------------------------------------

--
-- Table structure for table `ems_email`
--

DROP TABLE IF EXISTS `ems_email`;
CREATE TABLE IF NOT EXISTS `ems_email` (
  `id` varchar(40) NOT NULL,
  `firstName` varchar(256) NOT NULL,
  `lastName` varchar(256) NOT NULL,
  `email` varchar(256) NOT NULL,
  `contact` varchar(256) NOT NULL,
  `contactEmail` varchar(256) NOT NULL,
  `address` text NOT NULL,
  `created_at` date NOT NULL,
  `expire_at` date NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `events`
--

DROP TABLE IF EXISTS `events`;
CREATE TABLE IF NOT EXISTS `events` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `title` varchar(255) NOT NULL,
  `start_event` datetime NOT NULL,
  `end_event` datetime NOT NULL,
  `discipline` varchar(40) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `events`
--

INSERT INTO `events` (`id`, `title`, `start_event`, `end_event`, `discipline`) VALUES
(1, 'ttt', '2019-04-15 13:00:00', '2019-04-25 12:00:00', '{ffdb1cb8-af34-4381-8971-9784dcb516c5}');

-- --------------------------------------------------------

--
-- Table structure for table `fms_file`
--

DROP TABLE IF EXISTS `fms_file`;
CREATE TABLE IF NOT EXISTS `fms_file` (
  `ID` varchar(50) NOT NULL,
  `Link` varchar(200) NOT NULL,
  `CreatorID` varchar(50) NOT NULL,
  `CurrentUser` varchar(50) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `fms_file`
--

INSERT INTO `fms_file` (`ID`, `Link`, `CreatorID`, `CurrentUser`) VALUES
('{5DF79745-8FAE-4DAB-904E-B62517B0F2D0}', 'uploads/file/o8tbncfj1m.cpp', 'ryhan1630@cseku.ac.bd', 'rokeya@gmail.com');

-- --------------------------------------------------------

--
-- Table structure for table `fms_fileassign`
--

DROP TABLE IF EXISTS `fms_fileassign`;
CREATE TABLE IF NOT EXISTS `fms_fileassign` (
  `ID` varchar(100) NOT NULL,
  `sender` varchar(50) NOT NULL,
  `receiver` varchar(50) NOT NULL,
  `disciplineID` varchar(50) NOT NULL,
  `comment` varchar(200) NOT NULL,
  `timestamp` timestamp NOT NULL,
  `links` varchar(200) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `fms_fileassign`
--

INSERT INTO `fms_fileassign` (`ID`, `sender`, `receiver`, `disciplineID`, `comment`, `timestamp`, `links`) VALUES
('{5DF79745-8FAE-4DAB-904E-B62517B0F2D0}', 'ryhan1630@cseku.ac.bd', 'rokeya@gmail.com', '', 'Hello World', '2019-07-11 07:25:04', 'uploads/file/o8tbncfj1m.cpp ryhan1630@cseku.ac.bd 1562829904');

-- --------------------------------------------------------

--
-- Table structure for table `jms_applicant`
--

DROP TABLE IF EXISTS `jms_applicant`;
CREATE TABLE IF NOT EXISTS `jms_applicant` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `applicantID` varchar(40) NOT NULL,
  `JobID` varchar(40) NOT NULL,
  `cvID` varchar(100) NOT NULL,
  `SubmissionDate` datetime NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM AUTO_INCREMENT=14 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `jms_applicant`
--

INSERT INTO `jms_applicant` (`ID`, `applicantID`, `JobID`, `cvID`, `SubmissionDate`) VALUES
(9, 'hbappy79@gmail.com', '2', '7', '2018-08-13 05:03:17'),
(11, 'mkazi078@uottawa.ca', '2', '8', '2018-10-09 11:22:29'),
(12, 'hbappy79@gmail.com', '3', '9', '2018-10-22 07:48:25'),
(13, 'mkazi078@uottawa.ca', '3', '8', '2018-10-23 01:28:26');

-- --------------------------------------------------------

--
-- Table structure for table `jms_cv`
--

DROP TABLE IF EXISTS `jms_cv`;
CREATE TABLE IF NOT EXISTS `jms_cv` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `applicantID` varchar(40) NOT NULL,
  `Name` varchar(40) NOT NULL,
  `sector` varchar(45) NOT NULL,
  `email` varchar(45) NOT NULL,
  `phone` varchar(45) NOT NULL,
  `profile` varchar(500) NOT NULL,
  `technical_skill` varchar(500) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM AUTO_INCREMENT=18 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `jms_cv`
--

INSERT INTO `jms_cv` (`ID`, `applicantID`, `Name`, `sector`, `email`, `phone`, `profile`, `technical_skill`) VALUES
(9, 'hbappy79@gmail.com', 'Hadiuzzaman Bappy', 'Android Developer', 'hbappy79@gmail.com', '01325645897', 'Designing and developing advanced applications for the Android platform.', 'css,html,java,c,cpp'),
(17, 'mkazi078@uottawa.ca', 'Kazi Masudul Alam', 'Web Designer', 'mkazi078@uottawa.ca', '(+880) 1965-259846', 'Progressively evolve cross-platform ideas before impactful infomediaries. Energistically visualize tactical initiatives before cross-media catalysts for change.', 'XHTML,CSS,Javascript,Jquery,PHP,CVS / Subversion,OS X,Linux,Windows');

-- --------------------------------------------------------

--
-- Table structure for table `jms_cv_education`
--

DROP TABLE IF EXISTS `jms_cv_education`;
CREATE TABLE IF NOT EXISTS `jms_cv_education` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `cvID` int(11) NOT NULL,
  `instituition` varchar(45) NOT NULL,
  `subject` varchar(45) NOT NULL,
  `cgpa` varchar(45) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM AUTO_INCREMENT=31 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `jms_cv_education`
--

INSERT INTO `jms_cv_education` (`ID`, `cvID`, `instituition`, `subject`, `cgpa`) VALUES
(29, 17, 'Khulna University - Khulna', 'Computer Science and Engineering Displine', '4.0'),
(11, 9, 'Khulna University - Khulna', 'Computer Science and Engineering Displine', '4.0'),
(30, 17, 'Khulna University - Khulna', 'Computer Science and Engineering Displine', '4.0');

-- --------------------------------------------------------

--
-- Table structure for table `jms_cv_experience`
--

DROP TABLE IF EXISTS `jms_cv_experience`;
CREATE TABLE IF NOT EXISTS `jms_cv_experience` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `cvID` int(11) NOT NULL,
  `jobname` varchar(45) NOT NULL,
  `jobposition` varchar(45) NOT NULL,
  `workingyear` varchar(45) NOT NULL,
  `workdetails` varchar(500) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM AUTO_INCREMENT=26 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `jms_cv_experience`
--

INSERT INTO `jms_cv_experience` (`ID`, `cvID`, `jobname`, `jobposition`, `workingyear`, `workdetails`) VALUES
(11, 9, 'Data Scientist', 'Coder', '2015-016', 'Created machine learning models with Python and scikit-learn to predict energy usage of commercial buildings with 98% accuracy'),
(25, 17, 'Samsung Inc.', 'Senior Interface Designer', '2005-2007', 'Progressively reconceptualize multifunctional \"outside the box\" thinking through inexpensive methods of empowerment. Compellingly morph extensive niche markets with mission-critical ideas. Phosfluorescently deliver bricks-and-clicks strategic theme areas rather than scalable benefits.'),
(12, 9, 'Data Scientist', 'Coder', '2015-016', 'Created machine learning models with Python and scikit-learn to predict energy usage of commercial buildings with 98% accuracy');

-- --------------------------------------------------------

--
-- Table structure for table `jms_cv_skills`
--

DROP TABLE IF EXISTS `jms_cv_skills`;
CREATE TABLE IF NOT EXISTS `jms_cv_skills` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `cvID` int(11) NOT NULL,
  `name` varchar(100) NOT NULL,
  `details` varchar(500) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM AUTO_INCREMENT=32 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `jms_cv_skills`
--

INSERT INTO `jms_cv_skills` (`ID`, `cvID`, `name`, `details`) VALUES
(31, 17, 'Interface Design', 'Credibly streamline mission-critical value with multifunctional functionalities.'),
(30, 17, 'Interface Design', 'Credibly streamline mission-critical value with multifunctional functionalities.'),
(11, 9, 'UI maker', 'Strong knowledge of Android UI design principles, patterns, and best practices'),
(12, 9, 'UI maker', 'Strong knowledge of Android UI design principles, patterns, and best practices');

-- --------------------------------------------------------

--
-- Table structure for table `jms_job`
--

DROP TABLE IF EXISTS `jms_job`;
CREATE TABLE IF NOT EXISTS `jms_job` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `Title` varchar(100) NOT NULL,
  `Subtitle` varchar(100) NOT NULL,
  `PublishDate` date NOT NULL,
  `Organization` varchar(45) NOT NULL,
  `Qualification` varchar(500) NOT NULL,
  `Gender` varchar(45) NOT NULL,
  `AgeLimit` varchar(45) NOT NULL,
  `EmploymentType` varchar(45) NOT NULL,
  `NumberOfVacancy` int(11) NOT NULL,
  `Email` varchar(45) NOT NULL,
  `ContactNumber` varchar(45) NOT NULL,
  `Salary` varchar(45) DEFAULT NULL,
  `Location` varchar(255) DEFAULT NULL,
  `JobExperience` varchar(45) DEFAULT NULL,
  `LastDateOfApplication` date NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `jms_job`
--

INSERT INTO `jms_job` (`ID`, `Title`, `Subtitle`, `PublishDate`, `Organization`, `Qualification`, `Gender`, `AgeLimit`, `EmploymentType`, `NumberOfVacancy`, `Email`, `ContactNumber`, `Salary`, `Location`, `JobExperience`, `LastDateOfApplication`) VALUES
(2, 'Lecturer', 'This job position is experience, talented of to the University authority', '2018-08-10', 'Khulna University', 'H.S.C 5.0 + S.S.C 4.0', 'Male', '32', 'Permanent', 2, 'hbappy79@gmail.com', '01325659875', '65000', 'Khulna, Bangladesh', '2 years of teaching', '2018-08-23'),
(3, 'Librarian', 'a job post for seminar library,cse corridor', '2018-10-22', 'Khulna University', 'Honors pass', 'Anyone', '30', 'Full Time', 2, 'mkazi078@uottawa.ca', '01932056403', '25000', 'CSE,Khulna University', '-', '2018-10-31');

-- --------------------------------------------------------

--
-- Table structure for table `mytable`
--

DROP TABLE IF EXISTS `mytable`;
CREATE TABLE IF NOT EXISTS `mytable` (
  `serial` int(11) NOT NULL AUTO_INCREMENT,
  `category` varchar(20) DEFAULT NULL,
  `actName` varchar(45) DEFAULT NULL,
  `Organizer` varchar(100) DEFAULT NULL,
  `venu` varchar(200) DEFAULT NULL,
  `description` varchar(300) DEFAULT NULL,
  `date` date DEFAULT NULL,
  `time` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`serial`)
) ENGINE=MyISAM AUTO_INCREMENT=20 DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `notification_for_blood`
--

DROP TABLE IF EXISTS `notification_for_blood`;
CREATE TABLE IF NOT EXISTS `notification_for_blood` (
  `notificationID` int(11) NOT NULL AUTO_INCREMENT,
  `fromuserID` varchar(40) DEFAULT NULL,
  `touserID` varchar(40) DEFAULT NULL,
  `notification` varchar(1000) DEFAULT NULL,
  `read_unread` tinyint(1) DEFAULT NULL,
  `ndate` datetime DEFAULT NULL,
  `status` int(11) NOT NULL DEFAULT '0',
  `status_message` varchar(1000) DEFAULT NULL,
  `status_date` datetime DEFAULT NULL,
  PRIMARY KEY (`notificationID`)
) ENGINE=MyISAM AUTO_INCREMENT=200 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `notification_for_blood`
--

INSERT INTO `notification_for_blood` (`notificationID`, `fromuserID`, `touserID`, `notification`, `read_unread`, `ndate`, `status`, `status_message`, `status_date`) VALUES
(171, 'shish150225@gmail.com', 'rumon@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-29 11:19:51', 0, NULL, NULL),
(170, 'shish150225@gmail.com', 'monir150227@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-29 11:19:51', 0, NULL, NULL),
(169, 'shish150225@gmail.com', 'mkazi078@uottawa.ca', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-29 11:19:51', 0, NULL, NULL),
(167, 'shish150225@gmail.com', 'rumon@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-29 11:19:29', 0, NULL, NULL),
(168, 'shish150225@gmail.com', 'abir@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-29 11:19:51', 0, NULL, NULL),
(166, 'shish150225@gmail.com', 'rumon@gmail.com', 'BLOOD NEEDED!!! ', 0, '2018-10-29 11:19:10', 0, NULL, NULL),
(165, 'monir150227@gmail.com', 'shish150225@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-28 22:29:23', 0, NULL, NULL),
(164, 'monir150227@gmail.com', 'rumon@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-28 22:29:23', 0, NULL, NULL),
(163, 'monir150227@gmail.com', 'mkazi078@uottawa.ca', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-28 22:29:23', 0, NULL, NULL),
(162, 'monir150227@gmail.com', 'abir@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-28 22:29:23', 2, NULL, '2018-10-29 11:13:05'),
(161, 'shish150225@gmail.com', 'rumon@gmail.com', 'BLOOD NEEDED!!! \r\n', 0, '2018-10-28 20:15:12', 0, NULL, NULL),
(160, 'khalid@gmail.com', 'naim16@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-28 19:00:18', 0, NULL, NULL),
(159, 'shish150225@gmail.com', 'abir@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-28 18:50:22', 2, NULL, '2018-10-29 00:21:41'),
(158, 'abir@gmail.com', 'shish150225@gmail.com', 'BLOOD NEEDED!!!O+ Blood need argent', 0, '2018-10-28 18:38:21', 2, NULL, '2018-10-29 00:23:55'),
(157, 'mehadi.cse16@gmail.com', 'naim16@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-27 17:25:36', 1, 'ok\r\n', '2018-10-27 17:26:23'),
(156, 'mehadi.cse16@gmail.com', 'naim16@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-27 17:11:04', 2, NULL, '2018-10-27 17:26:26'),
(155, 'mehadi.cse16@gmail.com', 'naim16@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-27 17:09:27', 2, NULL, '2018-10-27 17:26:29'),
(154, 'mehadi.cse16@gmail.com', 'naim16@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-27 16:49:44', 1, 'cccc', '2018-10-27 16:52:13'),
(172, 'shish150225@gmail.com', 'abir@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-29 11:20:21', 0, NULL, NULL),
(173, 'shish150225@gmail.com', 'mkazi078@uottawa.ca', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-29 11:20:21', 0, NULL, NULL),
(174, 'shish150225@gmail.com', 'monir150227@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-29 11:20:21', 0, NULL, NULL),
(175, 'shish150225@gmail.com', 'rumon@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-29 11:20:21', 0, NULL, NULL),
(176, 'shish150225@gmail.com', 'abir@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-29 11:25:56', 1, 'yes', '2018-10-29 11:27:31'),
(177, 'shish150225@gmail.com', 'mkazi078@uottawa.ca', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-29 11:25:56', 0, NULL, NULL),
(178, 'shish150225@gmail.com', 'monir150227@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-29 11:25:56', 0, NULL, NULL),
(179, 'shish150225@gmail.com', 'rumon@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-29 11:25:56', 0, NULL, NULL),
(180, 'shish150225@gmail.com', 'naim16@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-29 11:31:16', 0, NULL, NULL),
(181, 'shish150225@gmail.com', 'naim16@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-29 11:32:01', 0, NULL, NULL),
(182, 'shish150225@gmail.com', 'naim16@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-29 11:35:59', 0, NULL, NULL),
(183, 'shish150225@gmail.com', 'naim16@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-29 11:36:13', 0, NULL, NULL),
(184, 'shish150225@gmail.com', 'naim16@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-29 11:36:52', 0, NULL, NULL),
(185, 'shish150225@gmail.com', 'naim16@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-29 11:40:12', 0, NULL, NULL),
(186, 'shish150225@gmail.com', 'naim16@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-29 11:40:17', 0, NULL, NULL),
(187, 'shish150225@gmail.com', 'naim16@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-29 11:42:47', 0, NULL, NULL),
(188, 'shish150225@gmail.com', 'naim16@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-29 11:43:38', 0, NULL, NULL),
(189, 'shish150225@gmail.com', 'rumon@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-29 11:45:41', 2, NULL, '2018-10-29 11:47:30'),
(190, 'rumon@gmail.com', 'aysha@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-29 11:49:38', 0, NULL, NULL),
(191, 'rumon@gmail.com', 'mahmud05@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-29 11:49:38', 0, NULL, NULL),
(192, 'shish150225@gmail.com', 'monir150227@gmail.com', 'BLOOD NEEDED!!! Wondering you might help! Blood will be needed after 3 month', 0, '2018-10-29 12:04:48', 0, NULL, NULL),
(193, 'naim16@gmail.com', 'monir150227@gmail.com', 'hey there!need blood\r\n', 0, '2018-10-29 12:14:10', 0, NULL, NULL),
(194, 'naim16@gmail.com', 'abir@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-29 13:06:43', 0, NULL, NULL),
(195, 'naim16@gmail.com', 'shish150225@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!hi', 0, '2018-10-29 13:09:53', 0, NULL, NULL),
(196, 'naim16@gmail.com', 'abir@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!Blood for O+', 0, '2018-10-29 13:15:34', 0, NULL, NULL),
(197, 'naim16@gmail.com', 'shish150225@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!Blood for O+', 0, '2018-10-29 13:15:34', 1, 'ok', '2018-10-29 13:16:16'),
(198, 'mefahimrahman@gmail.com', 'saimumislam96@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2019-04-12 22:17:26', 1, 'okk', '2019-04-12 22:17:51'),
(199, 'monir1527@cseku.ac.bd', 'mkazi078@uottawa.ca', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2019-04-15 11:27:54', 1, 'yes', '2019-04-15 11:28:29');

-- --------------------------------------------------------

--
-- Table structure for table `pms_hall_fee`
--

DROP TABLE IF EXISTS `pms_hall_fee`;
CREATE TABLE IF NOT EXISTS `pms_hall_fee` (
  `ID` varchar(40) NOT NULL,
  `UniversityID` int(11) NOT NULL,
  `Batch` int(11) NOT NULL,
  `Name` text NOT NULL,
  `Email` text NOT NULL,
  `HallName` text NOT NULL,
  `FiscalYear` text NOT NULL,
  `Discipline` text NOT NULL,
  `Date` date NOT NULL,
  `Admission` int(11) NOT NULL,
  `Institutional` int(11) NOT NULL,
  `IdentificationCard` int(11) NOT NULL,
  `SeatRent` int(11) NOT NULL,
  `Utensil` int(11) NOT NULL,
  `CommonRoom` int(11) NOT NULL,
  `Sports` int(11) NOT NULL,
  `ReligiousEvent` int(11) NOT NULL,
  `SecurityReturnable` int(11) NOT NULL,
  `Contingency` int(11) NOT NULL,
  `HallAnniversary` int(11) NOT NULL,
  `Fine` int(11) NOT NULL,
  `Others` int(11) NOT NULL,
  `Total` int(11) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `pms_hall_fee`
--

INSERT INTO `pms_hall_fee` (`ID`, `UniversityID`, `Batch`, `Name`, `Email`, `HallName`, `FiscalYear`, `Discipline`, `Date`, `Admission`, `Institutional`, `IdentificationCard`, `SeatRent`, `Utensil`, `CommonRoom`, `Sports`, `ReligiousEvent`, `SecurityReturnable`, `Contingency`, `HallAnniversary`, `Fine`, `Others`, `Total`) VALUES
('{29879C14-ED41-47B8-8A8B-5CF8CB8FF74B}', 160204, 16, 'Emamul Haque Manna', 'mannaemam@gmail.com', 'Khan Jahan Ali Hall', '2017/2018', 'Computer Science and Engineering', '2018-10-21', 1, 2, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 80),
('{C06F2047-430A-4DC7-8587-7DEADCF82A5E}', 160204, 16, 'Emamul Haque Manna', 'mannaemam@gmail.com', 'Khan Jahan Ali Hall', '2016/2017', 'Computer Science and Engineering', '2018-10-20', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2);

-- --------------------------------------------------------

--
-- Table structure for table `pms_link_project`
--

DROP TABLE IF EXISTS `pms_link_project`;
CREATE TABLE IF NOT EXISTS `pms_link_project` (
  `id` varchar(40) NOT NULL,
  `link` text NOT NULL,
  `project_id` varchar(40) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `project_id` (`project_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `pms_others_fee`
--

DROP TABLE IF EXISTS `pms_others_fee`;
CREATE TABLE IF NOT EXISTS `pms_others_fee` (
  `ID` varchar(40) NOT NULL,
  `UniversityID` int(40) NOT NULL,
  `Batch` text NOT NULL,
  `Name` text NOT NULL,
  `Email` text NOT NULL,
  `Discipline` text NOT NULL,
  `Date` date NOT NULL,
  `Description` text NOT NULL,
  `Total` int(40) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `pms_others_fee`
--

INSERT INTO `pms_others_fee` (`ID`, `UniversityID`, `Batch`, `Name`, `Email`, `Discipline`, `Date`, `Description`, `Total`) VALUES
('{48B9FB28-B876-4296-92B6-E8EE3453E488}', 160216, '16', 'Aswad  Alam', 'aswad@gmail.com', 'Computer Science and Engineering', '2018-10-22', 'DEVELOPMENT', 10),
('{76A1ED3E-84CD-42BB-8BF4-4822FC6F163E}', 160216, '16', 'Aswad  Alam', 'aswad@gmail.com', 'Computer Science and Engineering', '2018-10-22', 'CLUSTER', 5),
('{D3779D9D-A8E8-4C89-9579-7CC5429A5609}', 160204, '16', 'Emamul Haque Manna', 'mannaemam@gmail.com', 'Computer Science and Engineering', '2018-10-22', 'Cluster', 3);

-- --------------------------------------------------------

--
-- Table structure for table `pms_payment_type`
--

DROP TABLE IF EXISTS `pms_payment_type`;
CREATE TABLE IF NOT EXISTS `pms_payment_type` (
  `ID` varchar(40) CHARACTER SET utf8 NOT NULL,
  `PID` varchar(40) CHARACTER SET utf8 NOT NULL,
  `UniversityID` int(40) NOT NULL,
  `Type` text CHARACTER SET utf8 NOT NULL,
  `Date` date NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `pms_payment_type`
--

INSERT INTO `pms_payment_type` (`ID`, `PID`, `UniversityID`, `Type`, `Date`) VALUES
('{0EA045CA-E9EA-47E0-809F-D72F4A8A5E36}', '{8D94B890-D07A-43CD-B1D7-84F6177B99C8}', 160204, 'Registration Fee', '2018-10-19'),
('{20735E4D-1273-4D55-83C0-5362B566B005}', '{9A69A4D3-5166-4F65-80A9-5B6347A30041}', 160204, 'Registration Fee', '2018-10-20'),
('{2D20B95F-E2F2-49D3-9108-545E203CC3EC}', '{87956421-ABC3-4FAC-888B-41EA15315A69}', 160204, 'Registration Fee', '2018-10-20'),
('{59878D61-4946-4608-BE94-0C47D3A8EADA}', '{C06F2047-430A-4DC7-8587-7DEADCF82A5E}', 160204, 'Hall Fee', '2018-10-20'),
('{67AB46B8-1EEA-46A7-98E3-481D9E24CFC0}', '{8B38CC68-FBE3-49A7-B31C-DB8D2B915159}', 160204, 'Registration Fee', '2018-10-18'),
('{8AD3FC1A-6F81-4C08-A843-2B66D8498400}', '{AD69CEC5-D998-4C67-94FA-F235D4DBC077}', 160204, 'Registration Fee', '2018-10-20'),
('{909E7B34-B267-4924-8367-8A44AA42DE46}', '{E464BEA5-AFCC-4A96-9AEC-10587AF3C5AD}', 160216, 'Registration Fee', '2018-10-19'),
('{AF5104DA-382F-446E-8C53-10E096B9E1EE}', '{29879C14-ED41-47B8-8A8B-5CF8CB8FF74B}', 160204, 'Hall Fee', '2018-10-20'),
('{FBAE33C2-1575-4F90-A661-8D09B7356DBA}', '{47EE1E78-A76B-4122-8147-106E94B1C480}', 160204, 'Registration Fee', '2018-10-17');

-- --------------------------------------------------------

--
-- Table structure for table `pms_project`
--

DROP TABLE IF EXISTS `pms_project`;
CREATE TABLE IF NOT EXISTS `pms_project` (
  `id` varchar(40) NOT NULL,
  `thumbnail` text NOT NULL,
  `title` varchar(256) NOT NULL,
  `description` text NOT NULL,
  `language` varchar(256) NOT NULL,
  `year_id` varchar(40) NOT NULL,
  `term_id` varchar(40) NOT NULL,
  `course_id` varchar(40) NOT NULL,
  `discipline_id` varchar(40) NOT NULL,
  `teacher_id` varchar(40) NOT NULL,
  `created_at` timestamp NOT NULL,
  `updated_at` timestamp NOT NULL,
  PRIMARY KEY (`id`),
  KEY `year_id` (`year_id`),
  KEY `term_id` (`term_id`),
  KEY `course_id` (`course_id`),
  KEY `discipline_id` (`discipline_id`),
  KEY `teacher_id` (`teacher_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `pms_recharge`
--

DROP TABLE IF EXISTS `pms_recharge`;
CREATE TABLE IF NOT EXISTS `pms_recharge` (
  `ID` varchar(40) CHARACTER SET utf8 NOT NULL,
  `Date` date NOT NULL,
  `Email` text CHARACTER SET utf8 NOT NULL,
  `Amount` int(11) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `pms_recharge`
--

INSERT INTO `pms_recharge` (`ID`, `Date`, `Email`, `Amount`) VALUES
('{46D252E8-7694-4C15-AB10-99D14CEE73B1}', '2018-10-17', 'mannaemam@gmail.com', 75),
('{94CEC983-C608-408E-86B5-EE99012CE047}', '2018-10-19', 'aswad@gmail.com', 9);

-- --------------------------------------------------------

--
-- Table structure for table `pms_recharge_log`
--

DROP TABLE IF EXISTS `pms_recharge_log`;
CREATE TABLE IF NOT EXISTS `pms_recharge_log` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `Date` date NOT NULL,
  `Email` text CHARACTER SET utf8 NOT NULL,
  `Amount` int(11) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `pms_recharge_log`
--

INSERT INTO `pms_recharge_log` (`ID`, `Date`, `Email`, `Amount`) VALUES
(5, '2018-10-17', 'mannaemam@gmail.com', 100),
(6, '2018-10-19', 'aswad@gmail.com', 100),
(7, '2018-10-20', 'mannaemam@gmail.com', 50);

-- --------------------------------------------------------

--
-- Table structure for table `pms_reg_fee`
--

DROP TABLE IF EXISTS `pms_reg_fee`;
CREATE TABLE IF NOT EXISTS `pms_reg_fee` (
  `ID` varchar(40) CHARACTER SET utf8 NOT NULL,
  `UniversityID` int(40) NOT NULL,
  `Batch` int(40) NOT NULL,
  `Name` varchar(40) CHARACTER SET utf8 NOT NULL,
  `Email` varchar(40) CHARACTER SET utf8 NOT NULL,
  `Term` text CHARACTER SET utf8 NOT NULL,
  `Discipline` text CHARACTER SET utf8 NOT NULL,
  `Date` date NOT NULL,
  `AdmissionFee` double NOT NULL,
  `PayBook` double NOT NULL,
  `Security` double NOT NULL,
  `Transportation` double NOT NULL,
  `CourseRegistration` double NOT NULL,
  `Verification` double NOT NULL,
  `Retake` double NOT NULL,
  `ReRetake` double NOT NULL,
  `Bncc` double NOT NULL,
  `Library` double NOT NULL,
  `Medical` double NOT NULL,
  `Cultural` double NOT NULL,
  `ReligiousFee` double NOT NULL,
  `ExaminationFee` double NOT NULL,
  `SessionCharge` double NOT NULL,
  `Gradesheet` double NOT NULL,
  `ProvisionalCertificate` double NOT NULL,
  `MainCertificate` double NOT NULL,
  `Transcript` double NOT NULL,
  `SecurityLibrary` double NOT NULL,
  `EquivalenceCertificate` double NOT NULL,
  `FineLibrary` double NOT NULL,
  `FineRegistration` double NOT NULL,
  `Mc_Mi` double NOT NULL,
  `MphilPhd` double NOT NULL,
  `StudentWelfare` double NOT NULL,
  `Sports` double NOT NULL,
  `Publication` double NOT NULL,
  `Others` double NOT NULL,
  `Total` int(40) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `pms_reg_fee`
--

INSERT INTO `pms_reg_fee` (`ID`, `UniversityID`, `Batch`, `Name`, `Email`, `Term`, `Discipline`, `Date`, `AdmissionFee`, `PayBook`, `Security`, `Transportation`, `CourseRegistration`, `Verification`, `Retake`, `ReRetake`, `Bncc`, `Library`, `Medical`, `Cultural`, `ReligiousFee`, `ExaminationFee`, `SessionCharge`, `Gradesheet`, `ProvisionalCertificate`, `MainCertificate`, `Transcript`, `SecurityLibrary`, `EquivalenceCertificate`, `FineLibrary`, `FineRegistration`, `Mc_Mi`, `MphilPhd`, `StudentWelfare`, `Sports`, `Publication`, `Others`, `Total`) VALUES
('{47EE1E78-A76B-4122-8147-106E94B1C480}', 160204, 16, 'Emamul Haque Manna', 'mannaemam@gmail.com', '1-1', 'Computer Science and Engineering', '2018-10-17', 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3),
('{87956421-ABC3-4FAC-888B-41EA15315A69}', 160204, 16, 'Emamul Haque Manna', 'mannaemam@gmail.com', '2-2', 'Computer Science and Engineering', '2018-10-20', 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3),
('{8B38CC68-FBE3-49A7-B31C-DB8D2B915159}', 160204, 16, 'Emamul Haque Manna', 'mannaemam@gmail.com', '1-2', 'Computer Science and Engineering', '2018-10-18', 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2),
('{8D94B890-D07A-43CD-B1D7-84F6177B99C8}', 160204, 16, 'Emamul Haque Manna', 'mannaemam@gmail.com', '2-1', 'Computer Science and Engineering', '2018-10-19', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
('{9A69A4D3-5166-4F65-80A9-5B6347A30041}', 160204, 16, 'Emamul Haque Manna', 'mannaemam@gmail.com', '3-1', 'Computer Science and Engineering', '2018-10-20', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 4),
('{AD69CEC5-D998-4C67-94FA-F235D4DBC077}', 160204, 16, 'Emamul Haque Manna', 'mannaemam@gmail.com', '3-2', 'Computer Science and Engineering', '2018-10-20', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2),
('{E464BEA5-AFCC-4A96-9AEC-10587AF3C5AD}', 160216, 16, 'Aswad  Alam', 'aswad@gmail.com', '1-1', 'Computer Science and Engineering', '2018-10-19', 5, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10);

-- --------------------------------------------------------

--
-- Table structure for table `pms_student_project`
--

DROP TABLE IF EXISTS `pms_student_project`;
CREATE TABLE IF NOT EXISTS `pms_student_project` (
  `id` varchar(40) NOT NULL,
  `student_id` varchar(40) NOT NULL,
  `project_id` varchar(40) NOT NULL,
  `contribution` int(3) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `student_id` (`student_id`),
  KEY `project_id` (`project_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `reg_course`
--

DROP TABLE IF EXISTS `reg_course`;
CREATE TABLE IF NOT EXISTS `reg_course` (
  `ID` varchar(40) NOT NULL,
  `CourseNo` varchar(40) NOT NULL,
  `Title` varchar(100) NOT NULL,
  `Credit` double NOT NULL,
  `CourseTypeID` varchar(40) NOT NULL,
  `DisciplineID` varchar(40) NOT NULL,
  `PrequisiteID` varchar(40) DEFAULT NULL,
  `IsDeleted` tinyint(1) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `reg_course`
--

INSERT INTO `reg_course` (`ID`, `CourseNo`, `Title`, `Credit`, `CourseTypeID`, `DisciplineID`, `PrequisiteID`, `IsDeleted`) VALUES
('{1CD0842E-9FCF-4F58-BB6B-FB7E7B73E664}', 'CSE 1103', 'Structered Programming', 3, '{3DC4DDE5-514F-4BE4-8682-37EA32C3FDB7}', '{FFDB1CB8-AF34-4381-8971-9784DCB516C5}', NULL, 0),
('{24B98067-01EA-4B04-B815-3910BBAB2C29}', 'ece 3206', 'Data communication', 3, '{3DC4DDE5-514F-4BE4-8682-37EA32C3FDB7}', '{FFDB1CB8-AF34-4381-8971-9784DCB516C5}', NULL, 0),
('{2A038C6A-B6DA-408D-8458-7493D4EE5D6C}', 'cse-3200', 'Web Programming Lab', 1.5, '{EF5CA3BF-A886-4450-ABC4-DED45C7600C0}', '{FFDB1CB8-AF34-4381-8971-9784DCB516C5} ', '{7DFAB7F9-0C4F-4098-9140-0D89ABDD0A3D} ', 0),
('{53650FB7-D76E-459D-8B56-BC7A4919C0F6}', 'cse-4112', 'Computer Networks Lab', 1.5, '{EF5CA3BF-A886-4450-ABC4-DED45C7600C0}', '{FFDB1CB8-AF34-4381-8971-9784DCB516C5} ', NULL, 0),
('{683A3D91-D124-44AF-82A3-FB43837A4392}', 'cse-4111', 'Computer Networks', 3, '{3DC4DDE5-514F-4BE4-8682-37EA32C3FDB7}', '{FFDB1CB8-AF34-4381-8971-9784DCB516C5} ', '{1CD0842E-9FCF-4F58-BB6B-FB7E7B73E664} ', 0),
('{7DFAB7F9-0C4F-4098-9140-0D89ABDD0A3D}', 'CSE 1104', 'Structured Programming Laboratory', 1.5, '{EF5CA3BF-A886-4450-ABC4-DED45C7600C0}', '{FFDB1CB8-AF34-4381-8971-9784DCB516C5} ', NULL, 0),
('{B17BDB32-6D88-4537-9545-65D940E17EEF}', 'cse-2115', 'Advanced Programming Lab', 1.5, '{EF5CA3BF-A886-4450-ABC4-DED45C7600C0}', '{0CF37516-06FE-41CD-93AD-D2D1652509D6} ', '{1CD0842E-9FCF-4F58-BB6B-FB7E7B73E664} ', 1);

-- --------------------------------------------------------

--
-- Table structure for table `reg_course_resource`
--

DROP TABLE IF EXISTS `reg_course_resource`;
CREATE TABLE IF NOT EXISTS `reg_course_resource` (
  `CourseID` varchar(40) NOT NULL,
  `ResourceID` varchar(40) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `reg_course_sessional_type`
--

DROP TABLE IF EXISTS `reg_course_sessional_type`;
CREATE TABLE IF NOT EXISTS `reg_course_sessional_type` (
  `ID` varchar(40) NOT NULL,
  `Name` varchar(50) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `reg_course_sessional_type`
--

INSERT INTO `reg_course_sessional_type` (`ID`, `Name`) VALUES
('{126156BB-18ED-4CAB-8DB9-1C0F72BB63C1}', 'N/A'),
('{45B2147F-5FE0-4CC9-880C-C19EB6323955}', 'physics'),
('{4B342686-B38E-449C-AAD2-1F7DD77E6594}', 'chemistry'),
('{D1E54E03-CDEB-4155-AD0C-27C70A3A490C}', 'ece'),
('{D3F895D3-7389-487F-A604-0BD546DCC764}', 'software'),
('{F1D0443A-EC5D-41C4-94BA-D6F0D9AB1691}', 'hardware');

-- --------------------------------------------------------

--
-- Table structure for table `reg_course_student_registration`
--

DROP TABLE IF EXISTS `reg_course_student_registration`;
CREATE TABLE IF NOT EXISTS `reg_course_student_registration` (
  `ID` varchar(40) NOT NULL,
  `Regs_TeacherID` varchar(40) DEFAULT NULL,
  `StudentID` varchar(40) NOT NULL,
  `CourseID` varchar(40) NOT NULL,
  `SessionID` varchar(40) DEFAULT NULL,
  `YearID` varchar(40) DEFAULT NULL,
  `TermID` varchar(40) DEFAULT NULL,
  `IsRetake` tinyint(1) DEFAULT '0',
  `PreRetake` tinyint(1) NOT NULL DEFAULT '0',
  `Status` varchar(20) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `reg_course_student_registration`
--

INSERT INTO `reg_course_student_registration` (`ID`, `Regs_TeacherID`, `StudentID`, `CourseID`, `SessionID`, `YearID`, `TermID`, `IsRetake`, `PreRetake`, `Status`) VALUES
('{27D9E7CA-3B47-4FA6-8014-796F69E06B79}', 'mkazi078@uottawa.ca', 'lotif@gmail.com', '{7DFAB7F9-0C4F-4098-9140-0D89ABDD0A3D}', '{2FFA4D56-743A-47AF-9DDF-1EA28CA43251}', '{EA335D18-A1A8-4D15-9C7B-4A4700AD4543}', '{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}', 0, 1, 'registered'),
('{C2E9EB00-1751-4C91-8854-676FEC952714}', 'mkazi078@uottawa.ca', 'lotif@gmail.com', '{1CD0842E-9FCF-4F58-BB6B-FB7E7B73E664}', '{E11A301F-E0B9-47A5-AA3C-FB0B656B2A2A}', '{9F3A6CBC-0115-4EC2-ABB3-8CCA431F6C2B}', '{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}', 0, 0, 'registered'),
('{DFD4D9FF-DCA1-41CF-BC95-D604B237CB67}', 'mkazi078@uottawa.ca', 'rokeya@gmail.com', '{1CD0842E-9FCF-4F58-BB6B-FB7E7B73E664}', '{E11A301F-E0B9-47A5-AA3C-FB0B656B2A2A}', '{9F3A6CBC-0115-4EC2-ABB3-8CCA431F6C2B}', '{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}', 0, 0, 'registered'),
('{F2CF29E3-A0C8-4659-B5BA-638532427A8A}', 'mkazi078@uottawa.ca', 'lotif@gmail.com', '{7DFAB7F9-0C4F-4098-9140-0D89ABDD0A3D}', '{E11A301F-E0B9-47A5-AA3C-FB0B656B2A2A}', '{9F3A6CBC-0115-4EC2-ABB3-8CCA431F6C2B}', '{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}', 1, 0, 'failed');

-- --------------------------------------------------------

--
-- Table structure for table `reg_course_teacher`
--

DROP TABLE IF EXISTS `reg_course_teacher`;
CREATE TABLE IF NOT EXISTS `reg_course_teacher` (
  `ID` varchar(40) NOT NULL,
  `CourseID` varchar(40) NOT NULL,
  `TeacherID` varchar(40) NOT NULL,
  `SessionID` varchar(40) NOT NULL,
  `YearID` varchar(40) NOT NULL,
  `TermID` varchar(40) NOT NULL,
  `NoOfTests` int(10) DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `reg_course_teacher`
--

INSERT INTO `reg_course_teacher` (`ID`, `CourseID`, `TeacherID`, `SessionID`, `YearID`, `TermID`, `NoOfTests`) VALUES
('{03BC7D61-45DF-4714-B30F-FE48BF508443}', '{24B98067-01EA-4B04-B815-3910BBAB2C29}', 'mkazi078@uottawa.ca', '{E11A301F-E0B9-47A5-AA3C-FB0B656B2A2A}', '{A21965E4-4FE4-43AC-A77F-DABAC9B356F2}', '{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}', 4),
('{8872B54C-23D7-4358-A7F7-E2C245C14FB9}', '{1CD0842E-9FCF-4F58-BB6B-FB7E7B73E664}', 'mkazi078@uottawa.ca', '{E11A301F-E0B9-47A5-AA3C-FB0B656B2A2A}', '{9F3A6CBC-0115-4EC2-ABB3-8CCA431F6C2B}', '{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}', 4),
('{B504FC3B-18CB-4E2F-84BD-8C1229CBA920}', '{7DFAB7F9-0C4F-4098-9140-0D89ABDD0A3D}', 'avi@gmail.com', '{E11A301F-E0B9-47A5-AA3C-FB0B656B2A2A}', '{9F3A6CBC-0115-4EC2-ABB3-8CCA431F6C2B}', '{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}', 3),
('{FDDB9AAF-1495-49CC-A682-CE2DF2C8A561}', '{7DFAB7F9-0C4F-4098-9140-0D89ABDD0A3D}', 'avi@gmail.com', '{2FFA4D56-743A-47AF-9DDF-1EA28CA43251}', '{9F3A6CBC-0115-4EC2-ABB3-8CCA431F6C2B}', '{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}', 3);

-- --------------------------------------------------------

--
-- Table structure for table `reg_course_teacher_registration`
--

DROP TABLE IF EXISTS `reg_course_teacher_registration`;
CREATE TABLE IF NOT EXISTS `reg_course_teacher_registration` (
  `ID` varchar(40) NOT NULL,
  `TeacherID` varchar(40) NOT NULL,
  `SessionID` varchar(40) NOT NULL,
  `YearID` varchar(40) NOT NULL,
  `TermID` varchar(40) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `reg_course_teacher_registration`
--

INSERT INTO `reg_course_teacher_registration` (`ID`, `TeacherID`, `SessionID`, `YearID`, `TermID`) VALUES
('{CC494F52-1D3F-4877-BD28-91DF69556A2B}', 'mkazi078@uottawa.ca', '{E11A301F-E0B9-47A5-AA3C-FB0B656B2A2A}', '{9F3A6CBC-0115-4EC2-ABB3-8CCA431F6C2B}', '{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}');

-- --------------------------------------------------------

--
-- Table structure for table `reg_course_type`
--

DROP TABLE IF EXISTS `reg_course_type`;
CREATE TABLE IF NOT EXISTS `reg_course_type` (
  `ID` varchar(40) NOT NULL,
  `Name` varchar(30) NOT NULL,
  `SessionalTypeID` varchar(40) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `reg_course_type`
--

INSERT INTO `reg_course_type` (`ID`, `Name`, `SessionalTypeID`) VALUES
('{3DC4DDE5-514F-4BE4-8682-37EA32C3FDB7}', 'Theory', '{126156BB-18ED-4CAB-8DB9-1C0F72BB63C1}'),
('{5F886686-4EB1-48C8-A801-8D46233739D1}', 'Thesis', '{126156BB-18ED-4CAB-8DB9-1C0F72BB63C1}'),
('{EF5CA3BF-A886-4450-ABC4-DED45C7600C0}', 'Sessional', '{126156BB-18ED-4CAB-8DB9-1C0F72BB63C1}');

-- --------------------------------------------------------

--
-- Table structure for table `reg_registration_session`
--

DROP TABLE IF EXISTS `reg_registration_session`;
CREATE TABLE IF NOT EXISTS `reg_registration_session` (
  `ID` varchar(40) NOT NULL,
  `Name` varchar(30) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `reg_registration_session`
--

INSERT INTO `reg_registration_session` (`ID`, `Name`) VALUES
('{05DA37EB-6C62-45E9-A0E3-7C5C6943F6AD}', '2012-2013'),
('{1399EEA3-B939-4155-B9F3-4DAD4928C4D5}', '2014-2015'),
('{2FFA4D56-743A-47AF-9DDF-1EA28CA43251}', '2017-2018'),
('{65C2BA57-7231-497A-A5A7-90912259684C}', '2011-2012'),
('{A36A7057-CDB5-4E10-9E61-CCC85C74460E}', '2013-2014'),
('{DFF9E45F-6954-46A1-9088-D930EE460C3F}', '2015-2016'),
('{E11A301F-E0B9-47A5-AA3C-FB0B656B2A2A}', '2016-2017');

-- --------------------------------------------------------

--
-- Table structure for table `reg_term`
--

DROP TABLE IF EXISTS `reg_term`;
CREATE TABLE IF NOT EXISTS `reg_term` (
  `ID` varchar(40) NOT NULL,
  `Name` varchar(20) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `reg_term`
--

INSERT INTO `reg_term` (`ID`, `Name`) VALUES
('{6DE3CF58-3A1A-4D6A-88CF-83F22C27E0BA}', 'Special'),
('{AF8B217E-4E76-41B8-A02A-7115BD4A6BE6}', '2nd'),
('{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}', '1st');

-- --------------------------------------------------------

--
-- Table structure for table `reg_year`
--

DROP TABLE IF EXISTS `reg_year`;
CREATE TABLE IF NOT EXISTS `reg_year` (
  `ID` varchar(40) NOT NULL,
  `Name` varchar(20) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `reg_year`
--

INSERT INTO `reg_year` (`ID`, `Name`) VALUES
('{1FAC0F1A-9D60-43F6-AB07-C933D5A4AA30}', 'Phd 1st'),
('{326B168F-58CC-42F3-B71A-DFE8DBBC05E8}', 'MSc 1st'),
('{6780C884-E112-4F58-9503-E2110B615547}', '4th'),
('{9F3A6CBC-0115-4EC2-ABB3-8CCA431F6C2B}', '1st'),
('{A21965E4-4FE4-43AC-A77F-DABAC9B356F2}', '3rd'),
('{ADBEDD3E-D8EA-47AA-A068-C4C703DB4AE6}', 'MSc 2nd'),
('{B9D6CC05-7AD4-4666-80AB-80797A872743}', 'Phd 2nd'),
('{BB760927-4174-47E8-B68F-ACB8AA381B41}', '5th'),
('{CBE08035-94CD-4610-B4E2-A0E844184056}', 'Phd 4th'),
('{E3823AA6-6BE5-4A07-93EA-FA59DE4F616F}', 'Phd 3rd'),
('{EA335D18-A1A8-4D15-9C7B-4A4700AD4543}', '2nd');

-- --------------------------------------------------------

--
-- Table structure for table `rms_course_marks_result`
--

DROP TABLE IF EXISTS `rms_course_marks_result`;
CREATE TABLE IF NOT EXISTS `rms_course_marks_result` (
  `ID` varchar(40) NOT NULL,
  `CourseID` varchar(40) NOT NULL,
  `TeacherID` varchar(40) DEFAULT NULL,
  `SessionID` varchar(40) NOT NULL,
  `YearID` varchar(40) NOT NULL,
  `TermID` varchar(40) NOT NULL,
  `StudentID` varchar(40) NOT NULL,
  `MarksID` varchar(40) NOT NULL,
  `MarksValue` varchar(200) NOT NULL,
  `Status` varchar(40) DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `rms_course_marks_result`
--

INSERT INTO `rms_course_marks_result` (`ID`, `CourseID`, `TeacherID`, `SessionID`, `YearID`, `TermID`, `StudentID`, `MarksID`, `MarksValue`, `Status`) VALUES
('{357EFB93-A3A6-4044-A305-206F30EF9841}', '{1CD0842E-9FCF-4F58-BB6B-FB7E7B73E664}', 'mkazi078@uottawa.ca', '{E11A301F-E0B9-47A5-AA3C-FB0B656B2A2A}', '{9F3A6CBC-0115-4EC2-ABB3-8CCA431F6C2B}', '{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}', '160212', '{7E24DC07-CD2C-4360-A6E9-05A363C2EA08}', '8,20,20,10', ''),
('{4C7C80C2-8570-4895-B44D-67AA017F2EB0}', '{7DFAB7F9-0C4F-4098-9140-0D89ABDD0A3D}', 'avi@gmail.com', '{2FFA4D56-743A-47AF-9DDF-1EA28CA43251}', '{EA335D18-A1A8-4D15-9C7B-4A4700AD4543}', '{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}', '160212', '{236BBFE8-E4CF-4EEF-9C54-AD83FEF42ADB}', '10,50,25', ''),
('{A8BBB47F-B9B8-4E93-A137-39240B5842FC}', '{7DFAB7F9-0C4F-4098-9140-0D89ABDD0A3D}', 'avi@gmail.com', '{E11A301F-E0B9-47A5-AA3C-FB0B656B2A2A}', '{9F3A6CBC-0115-4EC2-ABB3-8CCA431F6C2B}', '{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}', '160212', '{236BBFE8-E4CF-4EEF-9C54-AD83FEF42ADB}', '5,20,10', ''),
('{F20DC6E0-95C7-40A0-9F09-04BF5C55618C}', '{1CD0842E-9FCF-4F58-BB6B-FB7E7B73E664}', 'mkazi078@uottawa.ca', '{E11A301F-E0B9-47A5-AA3C-FB0B656B2A2A}', '{9F3A6CBC-0115-4EC2-ABB3-8CCA431F6C2B}', '{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}', '160210', '{7E24DC07-CD2C-4360-A6E9-05A363C2EA08}', '10,28,25,25', '');

-- --------------------------------------------------------

--
-- Table structure for table `rms_course_marks_result_publish`
--

DROP TABLE IF EXISTS `rms_course_marks_result_publish`;
CREATE TABLE IF NOT EXISTS `rms_course_marks_result_publish` (
  `ID` varchar(40) NOT NULL,
  `CourseID` varchar(40) NOT NULL,
  `TeacherID` varchar(40) DEFAULT NULL,
  `SessionID` varchar(40) NOT NULL,
  `YearID` varchar(40) NOT NULL,
  `TermID` varchar(40) NOT NULL,
  `StudentID` varchar(40) NOT NULL,
  `HeaderID` varchar(200) NOT NULL,
  `HeaderName` varchar(200) NOT NULL,
  `HeaderMax` varchar(200) NOT NULL,
  `MarksValue` varchar(200) NOT NULL,
  `MarksTotal` varchar(20) NOT NULL,
  `Grades` varchar(200) NOT NULL,
  `GradeRanges` varchar(300) NOT NULL,
  `FinalGrade` varchar(20) NOT NULL,
  `GradePoint` double NOT NULL,
  `IsRetake` tinyint(4) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `rms_course_marks_result_publish`
--

INSERT INTO `rms_course_marks_result_publish` (`ID`, `CourseID`, `TeacherID`, `SessionID`, `YearID`, `TermID`, `StudentID`, `HeaderID`, `HeaderName`, `HeaderMax`, `MarksValue`, `MarksTotal`, `Grades`, `GradeRanges`, `FinalGrade`, `GradePoint`, `IsRetake`) VALUES
('{8A2C3585-D74F-4E27-B2AA-596CBF89E41F}', '{7DFAB7F9-0C4F-4098-9140-0D89ABDD0A3D}', 'avi@gmail.com', '{E11A301F-E0B9-47A5-AA3C-FB0B656B2A2A}', '{9F3A6CBC-0115-4EC2-ABB3-8CCA431F6C2B}', '{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}', '160212', 'att,assess,viva', 'Attendance,Assessment,Viva', '10,60,30', '5,20,10', '35', 'F,D,C,C+,B-,B,B+,A-,A,A+', '0-39,40-44,45-49,50-54,55-59,60-64,65-69,70-74,75-79,80-100', 'F', 0, 0),
('{93578272-8B2F-4913-9290-AFD706073FCE}', '{1CD0842E-9FCF-4F58-BB6B-FB7E7B73E664}', 'mkazi078@uottawa.ca', '{E11A301F-E0B9-47A5-AA3C-FB0B656B2A2A}', '{9F3A6CBC-0115-4EC2-ABB3-8CCA431F6C2B}', '{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}', '160210', 'att,assess,seca,secb', 'Attendance,Assessment,Section A,Section B', '10,30,30,30,30', '10,28,25,25', '88', 'F,D,C,C+,B-,B,B+,A-,A,A+', '0-39,40-44,45-49,50-54,55-59,60-64,65-69,70-74,75-79,80-100', 'A+', 4, 0),
('{B55CE2EF-8FA0-4B65-8CCB-D56781AC0281}', '{7DFAB7F9-0C4F-4098-9140-0D89ABDD0A3D}', 'avi@gmail.com', '{2FFA4D56-743A-47AF-9DDF-1EA28CA43251}', '{EA335D18-A1A8-4D15-9C7B-4A4700AD4543}', '{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}', '160212', 'att,assess,viva', 'Attendance,Assessment,Viva', '10,60,30', '10,50,25', '85', 'F,D,C,C+,B-,B,B+,A-,A,A+', '0-39,40-44,45-49,50-54,55-59,60-64,65-69,70-74,75-79,80-100', 'A', 3.75, 1),
('{B9976440-6CE3-4F51-B6CF-E0D5842A889B}', '{1CD0842E-9FCF-4F58-BB6B-FB7E7B73E664}', 'mkazi078@uottawa.ca', '{E11A301F-E0B9-47A5-AA3C-FB0B656B2A2A}', '{9F3A6CBC-0115-4EC2-ABB3-8CCA431F6C2B}', '{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}', '160212', 'att,assess,seca,secb', 'Attendance,Assessment,Section A,Section B', '10,30,30,30,30', '8,20,20,10', '58', 'F,D,C,C+,B-,B,B+,A-,A,A+', '0-39,40-44,45-49,50-54,55-59,60-64,65-69,70-74,75-79,80-100', 'B-', 2.75, 0);

-- --------------------------------------------------------

--
-- Table structure for table `rms_course_marks_tests`
--

DROP TABLE IF EXISTS `rms_course_marks_tests`;
CREATE TABLE IF NOT EXISTS `rms_course_marks_tests` (
  `ID` varchar(40) NOT NULL,
  `CourseID` varchar(40) NOT NULL,
  `TeacherID` varchar(40) NOT NULL,
  `SessionID` varchar(40) NOT NULL,
  `YearID` varchar(40) NOT NULL,
  `TermID` varchar(40) NOT NULL,
  `StudentID` varchar(40) NOT NULL,
  `MarksValue` varchar(200) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `rms_course_marks_tests`
--

INSERT INTO `rms_course_marks_tests` (`ID`, `CourseID`, `TeacherID`, `SessionID`, `YearID`, `TermID`, `StudentID`, `MarksValue`) VALUES
('{2008BCA1-57CD-4F6F-8C7F-BAAEA680C27D}', '{7DFAB7F9-0C4F-4098-9140-0D89ABDD0A3D}', 'avi@gmail.com', '{E11A301F-E0B9-47A5-AA3C-FB0B656B2A2A}', '{9F3A6CBC-0115-4EC2-ABB3-8CCA431F6C2B}', '{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}', '160212', '10,10,10'),
('{F747C284-82BC-4563-969A-2CF6523F2C7D}', '{1CD0842E-9FCF-4F58-BB6B-FB7E7B73E664}', 'mkazi078@uottawa.ca', '{E11A301F-E0B9-47A5-AA3C-FB0B656B2A2A}', '{9F3A6CBC-0115-4EC2-ABB3-8CCA431F6C2B}', '{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}', '160210', '13,X,X,X,X,X,X');

-- --------------------------------------------------------

--
-- Table structure for table `rms_grade_setup`
--

DROP TABLE IF EXISTS `rms_grade_setup`;
CREATE TABLE IF NOT EXISTS `rms_grade_setup` (
  `ID` varchar(40) NOT NULL,
  `Grades` varchar(200) NOT NULL,
  `Ranges` varchar(300) NOT NULL,
  `Cgpa` varchar(300) NOT NULL,
  `IsRetake` tinyint(1) DEFAULT '0',
  `IsDefault` tinyint(1) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `rms_grade_setup`
--

INSERT INTO `rms_grade_setup` (`ID`, `Grades`, `Ranges`, `Cgpa`, `IsRetake`, `IsDefault`) VALUES
('{77E5B72E-93A8-4F4C-8FEC-0D6EBE396CDD}', 'F,D,D,C,C+,B-,B,B+,A-,A', '0-39,40-44,45-49,50-54,55-59,60-64,65-69,70-74,75-79,80-100', '0.00,2.00,2.00,2.25,2.50,2.75,3.00,3.25,3.50,3.75', 1, 0),
('{FC3DBA75-AF9C-4533-825E-D8A01D076F60}', 'F,E,D,C,C+,B,B+,A-,A,A+', '0-39,40-44,45-49,50-54,55-59,60-64,65-69,70-74,75-79,80-100', '0.00,2.00,2.25,2.50,2.75,3.00,3.25,3.50,3.75,4.00', 0, 0),
('{FF75A9CD-E512-439C-AED2-9B176C8E68F1}', 'F,D,C,C+,B-,B,B+,A-,A,A+', '0-39,40-44,45-49,50-54,55-59,60-64,65-69,70-74,75-79,80-100', '0.00,2.00,2.25,2.50,2.75,3.00,3.25,3.50,3.75,4.00', 0, 1);

-- --------------------------------------------------------

--
-- Table structure for table `rms_marks_setup`
--

DROP TABLE IF EXISTS `rms_marks_setup`;
CREATE TABLE IF NOT EXISTS `rms_marks_setup` (
  `ID` varchar(40) NOT NULL,
  `CourseTypeID` varchar(40) NOT NULL,
  `HeaderID` varchar(200) NOT NULL,
  `HeaderName` varchar(200) NOT NULL,
  `HeaderMax` varchar(200) NOT NULL,
  `IsDefault` tinyint(1) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `rms_marks_setup`
--

INSERT INTO `rms_marks_setup` (`ID`, `CourseTypeID`, `HeaderID`, `HeaderName`, `HeaderMax`, `IsDefault`) VALUES
('{236BBFE8-E4CF-4EEF-9C54-AD83FEF42ADB}', '{EF5CA3BF-A886-4450-ABC4-DED45C7600C0}', 'att,assess,viva', 'Attendance,Assessment,Viva', '10,60,30', 1),
('{7E24DC07-CD2C-4360-A6E9-05A363C2EA08}', '{3DC4DDE5-514F-4BE4-8682-37EA32C3FDB7}', 'att,assess,seca,secb', 'Attendance,Assessment,Section A,Section B', '10,30,30,30,30', 1);

-- --------------------------------------------------------

--
-- Table structure for table `sms_scholarship`
--

DROP TABLE IF EXISTS `sms_scholarship`;
CREATE TABLE IF NOT EXISTS `sms_scholarship` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `title` varchar(70) DEFAULT NULL,
  `subTitle` varchar(1000) DEFAULT NULL,
  `category` varchar(45) DEFAULT NULL,
  `publishDate` date DEFAULT NULL,
  `organization` varchar(50) DEFAULT NULL,
  `gender` varchar(20) NOT NULL,
  `ageLimit` varchar(5) DEFAULT NULL,
  `email` varchar(20) DEFAULT NULL,
  `contact` varchar(20) DEFAULT NULL,
  `amount` varchar(10) DEFAULT NULL,
  `lastDate` date DEFAULT NULL,
  `status` varchar(20) DEFAULT NULL,
  `isDeleted` varchar(10) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=13 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `sms_scholarship`
--

INSERT INTO `sms_scholarship` (`id`, `title`, `subTitle`, `category`, `publishDate`, `organization`, `gender`, `ageLimit`, `email`, `contact`, `amount`, `lastDate`, `status`, `isDeleted`) VALUES
(11, 'Board Scholarship', 'We are offering a scholarship for the poor and meritorious students . So if you are interested then please apply before the last date.', 'merit', '2018-10-22', 'Khulna Board', 'Anyone', '22', 'khulna@gmail.com', '0166623633', '10000', '2018-10-31', NULL, NULL),
(6, 'Joynul Abedin Sriti', 'It plays a vital role in the student of the fine arts to give them scholarship.', 'merit', '2018-09-25', 'Joynul Abedin Trust Fo.', 'Anyone', '25', 'joynul123@gmail.com', '01800000008', '50000', '2018-10-25', NULL, NULL),
(7, 'Sheikh Kamal Sriti Scholarship', 'Sheikh kamal organization provide some financial help for poor students.', 'merit', '2018-09-25', 'sheikh kamal foundation', 'Male', '22', 'kamal12@gmail.com', '01721345678', '100000', '2018-09-30', NULL, NULL),
(9, 'Mahin Scholarship', 'i am a donor of Bangladesh. please contact me with your cv and apply.', 'merit', '2018-09-21', 'Mahin And Brothers', 'Anyone', '30', 'mahin@gmail.com', '0198887777', '50000', '2018-10-10', NULL, NULL);

-- --------------------------------------------------------

--
-- Table structure for table `sms_scholarship_applyscholarship`
--

DROP TABLE IF EXISTS `sms_scholarship_applyscholarship`;
CREATE TABLE IF NOT EXISTS `sms_scholarship_applyscholarship` (
  `studentId` int(11) NOT NULL,
  `scholarshipId` int(11) NOT NULL,
  `status` varchar(45) NOT NULL DEFAULT 'pending',
  `priority` varchar(45) NOT NULL DEFAULT '0',
  PRIMARY KEY (`studentId`,`scholarshipId`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `sms_scholarship_applyscholarship`
--

INSERT INTO `sms_scholarship_applyscholarship` (`studentId`, `scholarshipId`, `status`, `priority`) VALUES
(160216, 6, 'pending', '0');

-- --------------------------------------------------------

--
-- Table structure for table `sms_scholarship_catagory`
--

DROP TABLE IF EXISTS `sms_scholarship_catagory`;
CREATE TABLE IF NOT EXISTS `sms_scholarship_catagory` (
  `id` int(5) NOT NULL AUTO_INCREMENT,
  `catagoryName` varchar(45) NOT NULL,
  `shortName` varchar(45) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=11 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `sms_scholarship_catagory`
--

INSERT INTO `sms_scholarship_catagory` (`id`, `catagoryName`, `shortName`) VALUES
(1, 'Merit-based Scholarship', 'merit'),
(2, 'Grant in Aid', 'aid'),
(7, 'Cultural Scholarship', 'culture'),
(9, 'Board Scholarship', 'board');

-- --------------------------------------------------------

--
-- Table structure for table `sms_scholarship_cocurricular`
--

DROP TABLE IF EXISTS `sms_scholarship_cocurricular`;
CREATE TABLE IF NOT EXISTS `sms_scholarship_cocurricular` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `coName` varchar(100) DEFAULT NULL,
  `shortName` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=8 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `sms_scholarship_cocurricular`
--

INSERT INTO `sms_scholarship_cocurricular` (`id`, `coName`, `shortName`) VALUES
(1, 'Sports', 'SP'),
(3, 'Debate', 'DB'),
(4, 'Dance', 'DA'),
(5, 'Music', 'MU'),
(6, 'In Door Games', 'GA'),
(7, 'Acting', 'AC');

-- --------------------------------------------------------

--
-- Table structure for table `sms_scholarship_quota`
--

DROP TABLE IF EXISTS `sms_scholarship_quota`;
CREATE TABLE IF NOT EXISTS `sms_scholarship_quota` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `quotaName` varchar(45) DEFAULT NULL,
  `shortName` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=9 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `sms_scholarship_quota`
--

INSERT INTO `sms_scholarship_quota` (`id`, `quotaName`, `shortName`) VALUES
(1, 'Bangladesh Krira Shikkha Protishtan Quota', 'BKSPQ'),
(2, 'Freedom Fighter Quota', 'FFQ'),
(3, 'District Quota', 'DQ'),
(4, 'Autism Quota', 'AQ'),
(5, 'Tribal Quota', 'TQ'),
(8, 'Others Quota', 'OQ');

-- --------------------------------------------------------

--
-- Table structure for table `sms_scholarship_student`
--

DROP TABLE IF EXISTS `sms_scholarship_student`;
CREATE TABLE IF NOT EXISTS `sms_scholarship_student` (
  `universityId` int(11) NOT NULL,
  `age` varchar(5) NOT NULL,
  `fProf` varchar(45) DEFAULT NULL,
  `mProf` varchar(45) DEFAULT NULL,
  `income` varchar(45) DEFAULT NULL,
  `sibling` varchar(45) DEFAULT NULL,
  `reason` varchar(2000) DEFAULT NULL,
  `cocurricular` varchar(45) DEFAULT NULL,
  `quota` varchar(45) DEFAULT NULL,
  `term` varchar(5) NOT NULL,
  `cgpa` varchar(45) DEFAULT NULL,
  `picSource` varchar(350) DEFAULT NULL,
  `document` varchar(350) DEFAULT NULL,
  PRIMARY KEY (`universityId`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `sms_scholarship_student`
--

INSERT INTO `sms_scholarship_student` (`universityId`, `age`, `fProf`, `mProf`, `income`, `sibling`, `reason`, `cocurricular`, `quota`, `term`, `cgpa`, `picSource`, `document`) VALUES
(160216, '23', 'Businessmen', 'Housewife', '22222', '2', 'need for money', 'DB', '', '4-1', '2.6', 'account.jpg', 'Result.pdf');

-- --------------------------------------------------------

--
-- Table structure for table `tbl_cart`
--

DROP TABLE IF EXISTS `tbl_cart`;
CREATE TABLE IF NOT EXISTS `tbl_cart` (
  `ID` varchar(40) NOT NULL,
  `ProductID` varchar(40) NOT NULL,
  `UserID` varchar(40) NOT NULL,
  `Datetime` datetime NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_category`
--

DROP TABLE IF EXISTS `tbl_category`;
CREATE TABLE IF NOT EXISTS `tbl_category` (
  `cat_id` int(100) NOT NULL AUTO_INCREMENT,
  `categoryName` varchar(100) NOT NULL,
  PRIMARY KEY (`cat_id`)
) ENGINE=MyISAM AUTO_INCREMENT=12 DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_organizer`
--

DROP TABLE IF EXISTS `tbl_organizer`;
CREATE TABLE IF NOT EXISTS `tbl_organizer` (
  `org_id` int(100) NOT NULL AUTO_INCREMENT,
  `organizerName` varchar(100) NOT NULL,
  PRIMARY KEY (`org_id`)
) ENGINE=MyISAM AUTO_INCREMENT=13 DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_products`
--

DROP TABLE IF EXISTS `tbl_products`;
CREATE TABLE IF NOT EXISTS `tbl_products` (
  `ID` varchar(40) NOT NULL,
  `Name` varchar(40) NOT NULL,
  `CategoryID` varchar(40) NOT NULL,
  `Price` double NOT NULL,
  `OfferedCredit` double NOT NULL,
  `PictureAddress` varchar(200) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `tbl_products`
--

INSERT INTO `tbl_products` (`ID`, `Name`, `CategoryID`, `Price`, `OfferedCredit`, `PictureAddress`) VALUES
('{1A53D0E6-A580-4EA9-A2F9-B35CF92DDD01}', 'Forest Growth Simulation', '{3D212234-2F34-4AB0-83EF-1A772068403B}', 600, 65, '9781604697285r.jpg'),
('{34A3C9A7-4B6C-4398-8845-76399D6878E0}', 'Compiler', '{3D212234-2F34-4AB0-83EF-1A772068403B}', 300, 60, 'compilers.jpg'),
('{4308E3A8-E74F-49DC-A2BA-D26CEF37C37C}', 'Computer Graphics', '{3D212234-2F34-4AB0-83EF-1A772068403B}', 400, 30, 'graphics.jpeg'),
('{8C35D14E-BA72-4FEC-8703-1C7BF08760A1}', 'Java', '{3D212234-2F34-4AB0-83EF-1A772068403B}', 400, 40, 'bangla_c.jpg'),
('{9A912360-8C34-46EB-BFC2-698F237CC5D3}', 'Computer Networks', '{3D212234-2F34-4AB0-83EF-1A772068403B}', 200, 20, 'networking.png'),
('{C7DA13A3-5A5C-4361-BCA5-12EA1C632E0A}', 'Web Learning', '{44CAEE8D-A9D7-48C8-A2EA-A7463E00FCD6}', 400, 40, '9781785280351.png'),
('{CBF2600B-4FD3-41C8-A243-BFEE6C0DB1C3}', 'Bangla C', '{3D212234-2F34-4AB0-83EF-1A772068403B}', 400, 40, 'bangla_c.jpg'),
('{CC9C78DE-7022-4053-8951-B92BDF35D33D}', 'Deep Learning', '{44CAEE8D-A9D7-48C8-A2EA-A7463E00FCD6}', 550, 55, 'deep_learning.jpg'),
('{F14C8CA7-7F3F-45A0-95E5-2359805F2B96}', 'Computer Fundamentals', '{3D212234-2F34-4AB0-83EF-1A772068403B}', 260, 26, 'computer_fundamentals.jpg');

-- --------------------------------------------------------

--
-- Table structure for table `tbl_product_category`
--

DROP TABLE IF EXISTS `tbl_product_category`;
CREATE TABLE IF NOT EXISTS `tbl_product_category` (
  `ID` varchar(40) NOT NULL,
  `Category` varchar(40) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `tbl_product_category`
--

INSERT INTO `tbl_product_category` (`ID`, `Category`) VALUES
('{3D212234-2F34-4AB0-83EF-1A772068403B}', 'Book'),
('{44CAEE8D-A9D7-48C8-A2EA-A7463E00FCD6}', 'Thesis Book');

-- --------------------------------------------------------

--
-- Table structure for table `tms_assign`
--

DROP TABLE IF EXISTS `tms_assign`;
CREATE TABLE IF NOT EXISTS `tms_assign` (
  `id` varchar(40) NOT NULL,
  `assign_to` varchar(40) NOT NULL,
  `assign_by` varchar(40) NOT NULL,
  `assing_date` date NOT NULL,
  `comment` varchar(1000) NOT NULL,
  `status` int(11) NOT NULL DEFAULT '1'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `tms_assign`
--

INSERT INTO `tms_assign` (`id`, `assign_to`, `assign_by`, `assing_date`, `comment`, `status`) VALUES
('24', 'naeema@gmail.com', 'ryhan@gmail.com', '2018-09-25', 'TEST2                               \r\n                ', 0),
('24', 'naeema@gmail.com', 'ryhan@gmail.com', '2018-10-01', '                 test                ', 1),
('24', 'ryhan@gmail.com', 'ryhan@gmail.com', '2018-10-01', 'Test                          \r\n                ', 0),
('25', 'naeema@gmail.com', 'ryhan@gmail.com', '2018-10-08', 'Do the task very carefully                 \r\n                ', 1),
('27', 'naeema@gmail.com', 'ryhan@gmail.com', '2018-09-25', 'test\r\n                                  \r\n                ', 0),
('27', 'ryhan@gmail.com', 'naeema@gmail.com', '2018-09-25', '\r\n       tesy2                          \r\n                ', 1),
('28', 'ryhan@gmail.com', 'naeema@gmail.com', '2018-09-30', '\r\n          test                       \r\n                ', 1),
('32', 'ryhan@gmail.com', 'naeema@gmail.com', '2018-10-08', 'TEST               \r\n                ', 1),
('33', 'ryhan@gmail.com', 'naeema@gmail.com', '2018-10-08', 'TEST2                \r\n                ', 1),
('34', 'ryhan@gmail.com', 'ryhan@gmail.com', '2018-10-09', 'Study more and more               \r\n                ', 1),
('35', 'ryhan@gmail.com', 'avi@gmail.com', '2018-10-09', '  Do study                \r\n                ', 1);

-- --------------------------------------------------------

--
-- Table structure for table `tms_link_thesis`
--

DROP TABLE IF EXISTS `tms_link_thesis`;
CREATE TABLE IF NOT EXISTS `tms_link_thesis` (
  `id` varchar(40) NOT NULL,
  `link` text NOT NULL,
  `thesis_id` varchar(40) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `thesis_id` (`thesis_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tms_student_thesis`
--

DROP TABLE IF EXISTS `tms_student_thesis`;
CREATE TABLE IF NOT EXISTS `tms_student_thesis` (
  `id` varchar(40) NOT NULL,
  `student_id` varchar(40) NOT NULL,
  `thesis_id` varchar(40) NOT NULL,
  `contribution` int(3) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `student_id` (`student_id`),
  KEY `thesis_id` (`thesis_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tms_supervisor_thesis`
--

DROP TABLE IF EXISTS `tms_supervisor_thesis`;
CREATE TABLE IF NOT EXISTS `tms_supervisor_thesis` (
  `id` varchar(40) NOT NULL,
  `supervisor_id` varchar(40) NOT NULL,
  `thesis_id` varchar(40) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `supervisor_id` (`supervisor_id`),
  KEY `thesis_id` (`thesis_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tms_task`
--

DROP TABLE IF EXISTS `tms_task`;
CREATE TABLE IF NOT EXISTS `tms_task` (
  `id` varchar(40) NOT NULL,
  `task_name` varchar(20) NOT NULL,
  `task_creator` varchar(40) NOT NULL,
  `task_category` varchar(20) NOT NULL,
  `date_of_assign` date NOT NULL,
  `date_of_submission` date NOT NULL,
  `last_date_of_update` date NOT NULL,
  `progress` int(11) NOT NULL DEFAULT '0',
  `details` varchar(1000) NOT NULL,
  `attachment` varchar(400) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `tms_task`
--

INSERT INTO `tms_task` (`id`, `task_name`, `task_creator`, `task_category`, `date_of_assign`, `date_of_submission`, `last_date_of_update`, `progress`, `details`, `attachment`) VALUES
('1539613941', 'Class Test', 'ryhan@gmail.com', 'Study', '2018-10-15', '2018-10-26', '2018-10-15', 0, ';ljlj', '1539613941'),
('1539614267', 'Class Test', 'ryhan@gmail.com', 'Office', '2018-10-15', '2018-10-20', '2018-10-15', 0, 'tem,s', '1539614267.pdf'),
('24', 'test11', 'ryhan@gmail.com', 'Study', '2018-09-17', '2018-10-26', '2018-10-08', 11, 'DIP', '0'),
('25', 'Class Test', 'ryhan@gmail.com', 'Study', '2018-09-17', '2018-10-29', '2018-10-08', 6, 'DIP Class test', '0'),
('26', 'test11', 'ryhan@gmail.com', 'Study', '2018-08-09', '2018-10-26', '2018-10-08', 7, 'update date test', '0'),
('27', 'Solve the 5x5x5 cube', 'ryhan@gmail.com', 'Study', '2018-09-25', '2018-10-27', '2018-10-09', 3, 'You Have to solve the cube in 30 Minutes', '0'),
('32', 'test11111133', 'naeema@gmail.com', 'Appointment', '2018-10-08', '2018-10-31', '2018-10-09', 0, 'TEST', '0'),
('33', 'test2', 'naeema@gmail.com', 'Study', '2018-10-08', '2018-10-31', '2018-10-08', 0, 'TEST2', '0'),
('35', 'Class Test', 'avi@gmail.com', 'Study', '2018-10-09', '2018-10-30', '2018-10-09', 0, 'Class TEST', '0'),
('36', 'test11', '160230', 'hh', '2018-10-11', '2018-10-18', '2018-10-18', 0, 'lll', '0'),
('53', 'test11', '160230', 'hh', '2018-10-10', '2018-10-10', '2018-10-12', 0, ';lk;lkj', NULL),
('75', 'test', 'ryhan@gmail.com', 'Programming Contest', '2018-10-15', '2018-10-26', '2018-10-15', 0, 'kkkkk', '1539613080'),
('1560742408', 'test', 'mkazi078@uottawa.ca', 'Study', '2019-06-17', '2019-06-12', '2019-06-17', 0, 'll', '1560742408.pak');

-- --------------------------------------------------------

--
-- Table structure for table `tms_task_category`
--

DROP TABLE IF EXISTS `tms_task_category`;
CREATE TABLE IF NOT EXISTS `tms_task_category` (
  `id` int(11) NOT NULL,
  `task_type` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `tms_task_category`
--

INSERT INTO `tms_task_category` (`id`, `task_type`) VALUES
(1, 'Study'),
(2, 'Office'),
(3, 'Appointment'),
(4, 'Programming Contest');

-- --------------------------------------------------------

--
-- Table structure for table `tms_thesis`
--

DROP TABLE IF EXISTS `tms_thesis`;
CREATE TABLE IF NOT EXISTS `tms_thesis` (
  `id` varchar(40) NOT NULL,
  `thumbnail` text NOT NULL,
  `title` varchar(256) NOT NULL,
  `pdf_link` text,
  `description` text NOT NULL,
  `year_id` varchar(40) NOT NULL,
  `term_id` varchar(40) NOT NULL,
  `course_id` varchar(40) NOT NULL,
  `discipline_id` varchar(40) NOT NULL,
  `created_at` timestamp NOT NULL,
  `updated_at` timestamp NOT NULL,
  PRIMARY KEY (`id`),
  KEY `year_id` (`year_id`),
  KEY `term_id` (`term_id`),
  KEY `course_id` (`course_id`),
  KEY `discipline_id` (`discipline_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `ums_discipline`
--

DROP TABLE IF EXISTS `ums_discipline`;
CREATE TABLE IF NOT EXISTS `ums_discipline` (
  `ID` varchar(40) NOT NULL,
  `Name` varchar(50) NOT NULL,
  `ShortCode` varchar(20) DEFAULT NULL,
  `SchoolID` varchar(40) DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `ums_discipline`
--

INSERT INTO `ums_discipline` (`ID`, `Name`, `ShortCode`, `SchoolID`) VALUES
('{0CF37516-06FE-41CD-93AD-D2D1652509D6}', 'Mathematics', 'MATH', '{39DDC0C2-CFC2-4246-8748-8812B1751A5C}'),
('{560A0FC0-6221-497D-8D41-E584EE4BBEE3}', 'Architecture', 'ARCH', '{39DDC0C2-CFC2-4246-8748-8812B1751A5C}'),
('{63F3C00B-6168-4FBD-AB01-7A1FE413BDDE}', 'Forestry and Wood Technology', 'FWT', '{4D46079B-AFA3-40F1-B8D1-6CC9E9F56812}'),
('{AF41CC9F-3BCD-4952-9D02-17184CC40C79}', 'Urban and Rural Planning', 'URP', '{4D46079B-AFA3-40F1-B8D1-6CC9E9F56812}'),
('{E065BBA7-D0C5-4DFA-9768-81B6F056EB4A}', 'Foresty and Marine Resource Technology', 'FMRT', '{4D46079B-AFA3-40F1-B8D1-6CC9E9F56812}'),
('{E7280448-E379-424E-A11D-357F4334AC8D}', 'Physics', 'PHY', '{39DDC0C2-CFC2-4246-8748-8812B1751A5C}'),
('{FFDB1CB8-AF34-4381-8971-9784DCB516C5}', 'Computer Science and Engineering', 'CSE', '{39DDC0C2-CFC2-4246-8748-8812B1751A5C}');

-- --------------------------------------------------------

--
-- Table structure for table `ums_permission`
--

DROP TABLE IF EXISTS `ums_permission`;
CREATE TABLE IF NOT EXISTS `ums_permission` (
  `TableID` int(11) NOT NULL AUTO_INCREMENT,
  `ID` varchar(100) NOT NULL,
  `Name` varchar(100) NOT NULL,
  `Category` varchar(100) NOT NULL,
  PRIMARY KEY (`TableID`)
) ENGINE=InnoDB AUTO_INCREMENT=10965 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `ums_permission`
--

INSERT INTO `ums_permission` (`TableID`, `ID`, `Name`, `Category`) VALUES
(10765, 'COURSE_C', 'COURSE_C', 'COURSE'),
(10766, 'COURSE_R', 'COURSE_R', 'COURSE'),
(10767, 'COURSE_U', 'COURSE_U', 'COURSE'),
(10768, 'COURSE_D', 'COURSE_D', 'COURSE'),
(10769, 'COURSE_TYPE_C', 'COURSE_TYPE_C', 'COURSE TYPE'),
(10770, 'COURSE_TYPE_R', 'COURSE_TYPE_R', 'COURSE TYPE'),
(10771, 'COURSE_TYPE_U', 'COURSE_TYPE_U', 'COURSE TYPE'),
(10772, 'COURSE_TYPE_D', 'COURSE_TYPE_D', 'COURSE TYPE'),
(10773, 'COURSE_SESSIONAL_TYPE_C', 'COURSE_SESSIONAL_TYPE_C', 'COURSE SESSIONAL TYPE'),
(10774, 'COURSE_SESSIONAL_TYPE_R', 'COURSE_SESSIONAL_TYPE_R', 'COURSE SESSIONAL TYPE'),
(10775, 'COURSE_SESSIONAL_TYPE_U', 'COURSE_SESSIONAL_TYPE_U', 'COURSE SESSIONAL TYPE'),
(10776, 'COURSE_SESSIONAL_TYPE_D', 'COURSE_SESSIONAL_TYPE_D', 'COURSE SESSIONAL TYPE'),
(10777, 'DISCIPLINE_C', 'DISCIPLINE_C', 'DISCIPLINE'),
(10778, 'DISCIPLINE_R', 'DISCIPLINE_R', 'DISCIPLINE'),
(10779, 'DISCIPLINE_U', 'DISCIPLINE_U', 'DISCIPLINE'),
(10780, 'DISCIPLINE_D', 'DISCIPLINE_D', 'DISCIPLINE'),
(10781, 'FILE_C', 'FILE_C', 'FILE'),
(10782, 'FILE_R', 'FILE_R', 'FILE'),
(10783, 'FILE_U', 'FILE_U', 'FILE'),
(10784, 'FILE_D', 'FILE_D', 'FILE'),
(10785, 'PERMISSION_C', 'PERMISSION_C', 'PERMISSION'),
(10786, 'PERMISSION_R', 'PERMISSION_R', 'PERMISSION'),
(10787, 'PERMISSION_U', 'PERMISSION_U', 'PERMISSION'),
(10788, 'PERMISSION_D', 'PERMISSION_D', 'PERMISSION'),
(10789, 'REGISTRATION_C', 'REGISTRATION_C', 'REGISTRATION'),
(10790, 'REGISTRATION_R', 'REGISTRATION_R', 'REGISTRATION'),
(10791, 'REGISTRATION_U', 'REGISTRATION_U', 'REGISTRATION'),
(10792, 'REGISTRATION_D', 'REGISTRATION_D', 'REGISTRATION'),
(10793, 'RESULT_C', 'RESULT_C', 'RESULT'),
(10794, 'RESULT_R', 'RESULT_R', 'RESULT'),
(10795, 'RESULT_U', 'RESULT_U', 'RESULT'),
(10796, 'RESULT_D', 'RESULT_D', 'RESULT'),
(10797, 'ATTENDANCE_C', 'ATTENDANCE_C', 'ATTENDANCE'),
(10798, 'ATTENDANCE_R', 'ATTENDANCE_R', 'ATTENDANCE'),
(10799, 'ATTENDANCE_U', 'ATTENDANCE_U', 'ATTENDANCE'),
(10800, 'ATTENDANCE_D', 'ATTENDANCE_D', 'ATTENDANCE'),
(10801, 'MARKS_SETUP_C', 'MARKS_SETUP_C', 'MARKS_SETUP'),
(10802, 'MARKS_SETUP_R', 'MARKS_SETUP_R', 'MARKS_SETUP'),
(10803, 'MARKS_SETUP_U', 'MARKS_SETUP_U', 'MARKS_SETUP'),
(10804, 'MARKS_SETUP_D', 'MARKS_SETUP_D', 'MARKS_SETUP'),
(10805, 'GRADE_SETUP_C', 'GRADE_SETUP_C', 'GRADE_SETUP'),
(10806, 'GRADE_SETUP_R', 'GRADE_SETUP_R', 'GRADE_SETUP'),
(10807, 'GRADE_SETUP_U', 'GRADE_SETUP_U', 'GRADE_SETUP'),
(10808, 'GRADE_SETUP_D', 'GRADE_SETUP_D', 'GRADE_SETUP'),
(10809, 'ROLE_C', 'ROLE_C', 'ROLE'),
(10810, 'ROLE_R', 'ROLE_R', 'ROLE'),
(10811, 'ROLE_U', 'ROLE_U', 'ROLE'),
(10812, 'ROLE_D', 'ROLE_D', 'ROLE'),
(10813, 'POSITION_C', 'POSITION_C', 'POSITION'),
(10814, 'POSITION_R', 'POSITION_R', 'POSITION'),
(10815, 'POSITION_U', 'POSITION_U', 'POSITION'),
(10816, 'POSITION_D', 'POSITION_D', 'POSITION'),
(10817, 'PROJECT_C', 'PROJECT_C', 'PROJECT'),
(10818, 'PROJECT_R', 'PROJECT_R', 'PROJECT'),
(10819, 'PROJECT_U', 'PROJECT_U', 'PROJECT'),
(10820, 'PROJECT_D', 'PROJECT_D', 'PROJECT'),
(10821, 'QUESTION_C', 'QUESTION_C', 'QUESTION'),
(10822, 'QUESTION_R', 'QUESTION_R', 'QUESTION'),
(10823, 'QUESTION_U', 'QUESTION_U', 'QUESTION'),
(10824, 'QUESTION_D', 'QUESTION_D', 'QUESTION'),
(10825, 'SCHOOL_C', 'SCHOOL_C', 'SCHOOL'),
(10826, 'SCHOOL_R', 'SCHOOL_R', 'SCHOOL'),
(10827, 'SCHOOL_U', 'SCHOOL_U', 'SCHOOL'),
(10828, 'SCHOOL_D', 'SCHOOL_D', 'SCHOOL'),
(10829, 'SESSION_C', 'SESSION_C', 'SESSION'),
(10830, 'SESSION_R', 'SESSION_R', 'SESSION'),
(10831, 'SESSION_U', 'SESSION_U', 'SESSION'),
(10832, 'SESSION_D', 'SESSION_D', 'SESSION'),
(10833, 'SURVEY_C', 'SURVEY_C', 'SURVEY'),
(10834, 'SURVEY_R', 'SURVEY_R', 'SURVEY'),
(10835, 'SURVEY_U', 'SURVEY_U', 'SURVEY'),
(10836, 'SURVEY_D', 'SURVEY_D', 'SURVEY'),
(10837, 'SURVEY_QUESTION_C', 'SURVEY_QUESTION_C', 'SURVEY QUESTION'),
(10838, 'SURVEY_QUESTION_R', 'SURVEY_QUESTION_R', 'SURVEY QUESTION'),
(10839, 'SURVEY_QUESTION_U', 'SURVEY_QUESTION_U', 'SURVEY QUESTION'),
(10840, 'SURVEY_QUESTION_D', 'SURVEY_QUESTION_D', 'SURVEY QUESTION'),
(10841, 'SURVEY_QUESTION_TYPE_C', 'SURVEY_QUESTION_TYPE_C', 'SURVEY QUESTION TYPE'),
(10842, 'SURVEY_QUESTION_TYPE_R', 'SURVEY_QUESTION_TYPE_R', 'SURVEY QUESTION TYPE'),
(10843, 'SURVEY_QUESTION_TYPE_U', 'SURVEY_QUESTION_TYPE_U', 'SURVEY QUESTION TYPE'),
(10844, 'SURVEY_QUESTION_TYPE_D', 'SURVEY_QUESTION_TYPE_D', 'SURVEY QUESTION TYPE'),
(10845, 'SURVEY_QUESTION_FILLUP_C', 'SURVEY_QUESTION_FILLUP_C', 'SURVEY QUESTION FILLUP'),
(10846, 'SURVEY_QUESTION_FILLUP_R', 'SURVEY_QUESTION_FILLUP_R', 'SURVEY QUESTION FILLUP'),
(10847, 'SURVEY_QUESTION_FILLUP_U', 'SURVEY_QUESTION_FILLUP_U', 'SURVEY QUESTION FILLUP'),
(10848, 'SURVEY_QUESTION_FILLUP_D', 'SURVEY_QUESTION_FILLUP_D', 'SURVEY QUESTION FILLUP'),
(10849, 'TERM_C', 'TERM_C', 'TERM'),
(10850, 'TERM_R', 'TERM_R', 'TERM'),
(10851, 'TERM_U', 'TERM_U', 'TERM'),
(10852, 'TERM_D', 'TERM_D', 'TERM'),
(10853, 'USER_C', 'USER_C', 'USER'),
(10854, 'USER_R', 'USER_R', 'USER'),
(10855, 'USER_U', 'USER_U', 'USER'),
(10856, 'USER_D', 'USER_D', 'USER'),
(10857, 'YEAR_C', 'YEAR_C', 'YEAR'),
(10858, 'YEAR_R', 'YEAR_R', 'YEAR'),
(10859, 'YEAR_U', 'YEAR_U', 'YEAR'),
(10860, 'YEAR_D', 'YEAR_D', 'YEAR'),
(10861, 'JOB_C', 'JOB_C', 'JOB'),
(10862, 'JOB_R', 'JOB_R', 'JOB'),
(10863, 'JOB_U', 'JOB_U', 'JOB'),
(10864, 'JOB_D', 'JOB_D', 'JOB'),
(10865, 'CLUB_C', 'CLUB_C', 'CLUB'),
(10866, 'CLUB_R', 'CLUB_R', 'CLUB'),
(10867, 'CLUB_U', 'CLUB_U', 'CLUB'),
(10868, 'CLUB_D', 'CLUB_D', 'CLUB'),
(10869, 'DISCUSSION_C', 'DISCUSSION_C', 'DISCUSSION'),
(10870, 'DISCUSSION_R', 'DISCUSSION_R', 'DISCUSSION'),
(10871, 'DISCUSSION_U', 'DISCUSSION_U', 'DISCUSSION'),
(10872, 'DISCUSSION_D', 'DISCUSSION_D', 'DISCUSSION'),
(10873, 'DISCUSSION_CAT_C', 'DISCUSSION_CAT_C', 'DISCUSSION CATEGORY'),
(10874, 'DISCUSSION_CAT_R', 'DISCUSSION_CAT_R', 'DISCUSSION CATEGORY'),
(10875, 'DISCUSSION_CAT_U', 'DISCUSSION_CAT_U', 'DISCUSSION CATEGORY'),
(10876, 'DISCUSSION_CAT_D', 'DISCUSSION_CAT_D', 'DISCUSSION CATEGORY'),
(10877, 'DISCUSSION_COMMENT_C', 'DISCUSSION_COMMENT_C', 'DISCUSSION COMMENT'),
(10878, 'DISCUSSION_COMMENT_R', 'DISCUSSION_COMMENT_R', 'DISCUSSION COMMENT'),
(10879, 'DISCUSSION_COMMENT_U', 'DISCUSSION_COMMENT_U', 'DISCUSSION COMMENT'),
(10880, 'DISCUSSION_COMMENT_D', 'DISCUSSION_COMMENT_D', 'DISCUSSION COMMENT'),
(10881, 'TASK_C', 'TASK_C', 'TASK'),
(10882, 'TASK_R', 'TASK_R', 'TASK'),
(10883, 'TASK_U', 'TASK_U', 'TASK'),
(10884, 'TASK_D', 'TASK_D', 'TASK'),
(10885, 'TASK_CATEGORY_C', 'TASK_CATEGORY_C', 'TASK_CATEGORY'),
(10886, 'TASK_CATEGORY_R', 'TASK_CATEGORY_R', 'TASK_CATEGORY'),
(10887, 'TASK_CATEGORY_U', 'TASK_CATEGORY_U', 'TASK_CATEGORY'),
(10888, 'TASK_CATEGORY_D', 'TASK_CATEGORY_D', 'TASK_CATEGORY'),
(10889, 'ASSET_C', 'ASSET_C', 'ASSET'),
(10890, 'ASSET_R', 'ASSET_R', 'ASSET'),
(10891, 'ASSET_U', 'ASSET_U', 'ASSET'),
(10892, 'ASSET_D', 'ASSET_D', 'ASSET'),
(10893, 'THESIS_C', 'THESIS_C', 'THESIS'),
(10894, 'THESIS_R', 'THESIS_R', 'THESIS'),
(10895, 'THESIS_U', 'THESIS_U', 'THESIS'),
(10896, 'THESIS_D', 'THESIS_D', 'THESIS'),
(10897, 'EMAIL_C', 'EMAIL_C', 'EMAIL'),
(10898, 'EMAIL_R', 'EMAIL_R', 'EMAIL'),
(10899, 'EMAIL_U', 'EMAIL_U', 'EMAIL'),
(10900, 'EMAIL_D', 'EMAIL_D', 'EMAIL'),
(10901, 'VIDEO_C', 'VIDEO_C', 'VIDEO'),
(10902, 'VIDEO_R', 'VIDEO_R', 'VIDEO'),
(10903, 'VIDEO_U', 'VIDEO_U', 'VIDEO'),
(10904, 'VIDEO_D', 'VIDEO_D', 'VIDEO'),
(10905, 'VIDEO_COMMENT_C', 'VIDEO_COMMENT_C', 'VIDEO COMMENT'),
(10906, 'VIDEO_COMMENT_R', 'VIDEO_COMMENT_R', 'VIDEO COMMENT'),
(10907, 'VIDEO_COMMENT_U', 'VIDEO_COMMENT_U', 'VIDEO COMMENT'),
(10908, 'VIDEO_COMMENT_D', 'VIDEO_COMMENT_D', 'VIDEO COMMENT'),
(10909, 'CALENDAR_C', 'CALENDAR_C', 'CALENDAR'),
(10910, 'CALENDAR_R', 'CALENDAR_R', 'CALENDAR'),
(10911, 'CALENDAR_U', 'CALENDAR_U', 'CALENDAR'),
(10912, 'CALENDAR_D', 'CALENDAR_D', 'CALENDAR'),
(10913, 'BLOOD_C', 'BLOOD_C', 'BLOOD'),
(10914, 'BLOOD_R', 'BLOOD_R', 'BLOOD'),
(10915, 'BLOOD_U', 'BLOOD_U', 'BLOOD'),
(10916, 'BLOOD_D', 'BLOOD_D', 'BLOOD'),
(10917, 'PAYMENT_C', 'PAYMENT_C', 'PAYMENT'),
(10918, 'PAYMENT_R', 'PAYMENT_R', 'PAYMENT'),
(10919, 'PAYMENT_U', 'PAYMENT_U', 'PAYMENT'),
(10920, 'PAYMENT_D', 'PAYMENT_D', 'PAYMENT'),
(10921, 'PAYMENT_LOG_C', 'PAYMENT_LOG_C', 'PAYMENT_LOG'),
(10922, 'PAYMENT_LOG_R', 'PAYMENT_LOG_R', 'PAYMENT_LOG'),
(10923, 'PAYMENT_LOG_U', 'PAYMENT_LOG_U', 'PAYMENT_LOG'),
(10924, 'PAYMENT_LOG_D', 'PAYMENT_LOG_D', 'PAYMENT_LOG'),
(10925, 'PAYMENT_RECHARGE_C', 'PAYMENT_RECHARGE_C', 'PAYMENT_RECHARGE'),
(10926, 'PAYMENT_RECHARGE_R', 'PAYMENT_RECHARGE_R', 'PAYMENT_RECHARGE'),
(10927, 'PAYMENT_RECHARGE_U', 'PAYMENT_RECHARGE_U', 'PAYMENT_RECHARGE'),
(10928, 'PAYMENT_RECHARGE_D', 'PAYMENT_RECHARGE_D', 'PAYMENT_RECHARGE'),
(10929, 'PRODUCT_C', 'PRODUCT_C', 'PRODUCT'),
(10930, 'PRODUCT_R', 'PRODUCT_R', 'PRODUCT'),
(10931, 'PRODUCT_U', 'PRODUCT_U', 'PRODUCT'),
(10932, 'PRODUCT_D', 'PRODUCT_D', 'PRODUCT'),
(10933, 'JOB_C', 'JOB_C', 'JOB'),
(10934, 'JOB_R', 'JOB_R', 'JOB'),
(10935, 'JOB_U', 'JOB_U', 'JOB'),
(10936, 'JOB_D', 'JOB_D', 'JOB'),
(10937, 'SCHOLARSHIP_C', 'SCHOLARSHIP_C', 'SCHOLARSHIP'),
(10938, 'SCHOLARSHIP_R', 'SCHOLARSHIP_R', 'SCHOLARSHIP'),
(10939, 'SCHOLARSHIP_U', 'SCHOLARSHIP_U', 'SCHOLARSHIP'),
(10940, 'SCHOLARSHIP_D', 'SCHOLARSHIP_D', 'SCHOLARSHIP'),
(10941, 'SCHOLARSHIP_TYPE_C', 'SCHOLARSHIP_TYPE_C', 'SCHOLARSHIP_TYPE'),
(10942, 'SCHOLARSHIP_TYPE_R', 'SCHOLARSHIP_TYPE_R', 'SCHOLARSHIP_TYPE'),
(10943, 'SCHOLARSHIP_TYPE_U', 'SCHOLARSHIP_TYPE_U', 'SCHOLARSHIP_TYPE'),
(10944, 'SCHOLARSHIP_TYPE_D', 'SCHOLARSHIP_TYPE_D', 'SCHOLARSHIP_TYPE'),
(10945, 'SCHOLARSHIP_APPLIED_C', 'SCHOLARSHIP_APPLIED_C', 'SCHOLARSHIP_APPLIED'),
(10946, 'SCHOLARSHIP_APPLIED_R', 'SCHOLARSHIP_APPLIED_R', 'SCHOLARSHIP_APPLIED'),
(10947, 'SCHOLARSHIP_APPLIED_U', 'SCHOLARSHIP_APPLIED_U', 'SCHOLARSHIP_APPLIED'),
(10948, 'SCHOLARSHIP_APPLIED_D', 'SCHOLARSHIP_APPLIED_D', 'SCHOLARSHIP_APPLIED'),
(10949, 'SCHOLARSHIP_CV_C', 'SCHOLARSHIP_CV_C', 'SCHOLARSHIP_CV'),
(10950, 'SCHOLARSHIP_CV_R', 'SCHOLARSHIP_CV_R', 'SCHOLARSHIP_CV'),
(10951, 'SCHOLARSHIP_CV_U', 'SCHOLARSHIP_CV_U', 'SCHOLARSHIP_CV'),
(10952, 'SCHOLARSHIP_CV_D', 'SCHOLARSHIP_CV_D', 'SCHOLARSHIP_CV'),
(10953, 'CCA_C', 'CCA_C', 'CCA'),
(10954, 'CCA_R', 'CCA_R', 'CCA'),
(10955, 'CCA_U', 'CCA_U', 'CCA'),
(10956, 'CCA_D', 'CCA_D', 'CCA'),
(10957, 'BUDGET', 'BUDGET_C', 'BUDGET'),
(10958, 'BUDGET_R', 'BUDGET_R', 'BUDGET'),
(10959, 'BUDGET_U', 'BUDGET_U', 'BUDGET'),
(10960, 'BUDGET_D', 'BUDGET_D', 'BUDGET'),
(10961, 'BOOK_C', 'BOOK_C', 'BOOK'),
(10962, 'BOOK_R', 'BOOK_R', 'BOOK'),
(10963, 'BOOK_U', 'BOOK_U', 'BOOK'),
(10964, 'BOOK_D', 'BOOK_D', 'BOOK');

-- --------------------------------------------------------

--
-- Table structure for table `ums_position`
--

DROP TABLE IF EXISTS `ums_position`;
CREATE TABLE IF NOT EXISTS `ums_position` (
  `ID` varchar(40) NOT NULL,
  `Name` varchar(50) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `ums_position`
--

INSERT INTO `ums_position` (`ID`, `Name`) VALUES
('{1BFE76DB-C2AA-4FAA-A23B-F43E6150A2F6}', 'Section Officer'),
('{2E024DF5-BD45-4EF2-A5E3-43BCA3E9777F}', 'Pro-vice Chancellor'),
('{64D25DDA-16B6-47B8-BBFC-4E2AAF5680C7}', 'Assistant Professor'),
('{7CDA1F32-A2F8-4469-B5A8-C2038FCE1F9A}', 'Lecturer'),
('{818DE12F-60CC-42E4-BAEC-48EAAED65179}', 'Dean of School'),
('{928EE9FF-E02D-470F-9A6A-AD0EB38B848F}', 'Vice Chancellor'),
('{92FDDA3F-1E91-4AA3-918F-EB595F85790C}', 'Daywise Worker'),
('{932CB0EE-76C2-448E-A40E-2D167EECC479}', 'Registrar'),
('{ADA027D3-21C1-47AF-A21D-759CAFCFE58D}', 'Assistant Registrar'),
('{B76EB035-EA26-4CEB-B029-1C6129574D98}', 'Librarian'),
('{B78C7A7B-4D38-4025-8170-7B8C9F291946}', 'Head of Discipline'),
('{C27B6BCF-FB83-4F3D-85CA-B7870D8B12D0}', 'Associate Professor'),
('{EB4880E2-01B3-4C6E-A2C9-89B6E5427C0A}', 'Professor');

-- --------------------------------------------------------

--
-- Table structure for table `ums_role`
--

DROP TABLE IF EXISTS `ums_role`;
CREATE TABLE IF NOT EXISTS `ums_role` (
  `ID` varchar(40) NOT NULL,
  `Name` varchar(50) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `ums_role`
--

INSERT INTO `ums_role` (`ID`, `Name`) VALUES
('administrator', 'Administrator'),
('registration coordinator', 'Registration Coordinator'),
('student', 'Student'),
('stuff', 'Stuff'),
('tabulator', 'Tabulator'),
('teacher', 'Teacher');

-- --------------------------------------------------------

--
-- Table structure for table `ums_role_permission`
--

DROP TABLE IF EXISTS `ums_role_permission`;
CREATE TABLE IF NOT EXISTS `ums_role_permission` (
  `Row` int(11) NOT NULL AUTO_INCREMENT,
  `RoleID` varchar(40) NOT NULL,
  `PermissionID` varchar(100) NOT NULL,
  PRIMARY KEY (`Row`)
) ENGINE=InnoDB AUTO_INCREMENT=6676 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `ums_role_permission`
--

INSERT INTO `ums_role_permission` (`Row`, `RoleID`, `PermissionID`) VALUES
(5575, 'registration coordinator', 'ASSET_C'),
(5576, 'registration coordinator', 'ASSET_R'),
(5577, 'registration coordinator', 'ASSET_U'),
(5578, 'registration coordinator', 'ASSET_D'),
(5579, 'registration coordinator', 'ATTENDANCE_C'),
(5580, 'registration coordinator', 'ATTENDANCE_R'),
(5581, 'registration coordinator', 'ATTENDANCE_U'),
(5582, 'registration coordinator', 'ATTENDANCE_D'),
(5583, 'registration coordinator', 'BLOOD_C'),
(5584, 'registration coordinator', 'BLOOD_R'),
(5585, 'registration coordinator', 'BLOOD_U'),
(5586, 'registration coordinator', 'CALENDAR_R'),
(5587, 'registration coordinator', 'CLUB_C'),
(5588, 'registration coordinator', 'CLUB_R'),
(5589, 'registration coordinator', 'CLUB_U'),
(5590, 'registration coordinator', 'CLUB_D'),
(5591, 'registration coordinator', 'COURSE_C'),
(5592, 'registration coordinator', 'COURSE_R'),
(5593, 'registration coordinator', 'COURSE_U'),
(5594, 'registration coordinator', 'COURSE_D'),
(5595, 'registration coordinator', 'COURSE_SESSIONAL_TYPE_C'),
(5596, 'registration coordinator', 'COURSE_SESSIONAL_TYPE_R'),
(5597, 'registration coordinator', 'COURSE_SESSIONAL_TYPE_U'),
(5598, 'registration coordinator', 'COURSE_SESSIONAL_TYPE_D'),
(5599, 'registration coordinator', 'COURSE_TYPE_C'),
(5600, 'registration coordinator', 'COURSE_TYPE_R'),
(5601, 'registration coordinator', 'COURSE_TYPE_U'),
(5602, 'registration coordinator', 'COURSE_TYPE_D'),
(5603, 'registration coordinator', 'DISCIPLINE_C'),
(5604, 'registration coordinator', 'DISCIPLINE_R'),
(5605, 'registration coordinator', 'DISCIPLINE_U'),
(5606, 'registration coordinator', 'DISCIPLINE_D'),
(5607, 'registration coordinator', 'DISCUSSION_C'),
(5608, 'registration coordinator', 'DISCUSSION_R'),
(5609, 'registration coordinator', 'DISCUSSION_U'),
(5610, 'registration coordinator', 'DISCUSSION_D'),
(5611, 'registration coordinator', 'DISCUSSION_CAT_C'),
(5612, 'registration coordinator', 'DISCUSSION_CAT_R'),
(5613, 'registration coordinator', 'DISCUSSION_CAT_U'),
(5614, 'registration coordinator', 'DISCUSSION_CAT_D'),
(5615, 'registration coordinator', 'DISCUSSION_COMMENT_C'),
(5616, 'registration coordinator', 'DISCUSSION_COMMENT_R'),
(5617, 'registration coordinator', 'DISCUSSION_COMMENT_U'),
(5618, 'registration coordinator', 'DISCUSSION_COMMENT_D'),
(5619, 'registration coordinator', 'EMAIL_C'),
(5620, 'registration coordinator', 'EMAIL_R'),
(5621, 'registration coordinator', 'EMAIL_U'),
(5622, 'registration coordinator', 'EMAIL_D'),
(5623, 'registration coordinator', 'FILE_C'),
(5624, 'registration coordinator', 'FILE_R'),
(5625, 'registration coordinator', 'FILE_U'),
(5626, 'registration coordinator', 'FILE_D'),
(5627, 'registration coordinator', 'GRADE_SETUP_C'),
(5628, 'registration coordinator', 'GRADE_SETUP_R'),
(5629, 'registration coordinator', 'GRADE_SETUP_U'),
(5630, 'registration coordinator', 'GRADE_SETUP_D'),
(5631, 'registration coordinator', 'JOB_C'),
(5632, 'registration coordinator', 'JOB_R'),
(5633, 'registration coordinator', 'JOB_U'),
(5634, 'registration coordinator', 'JOB_D'),
(5635, 'registration coordinator', 'MARKS_SETUP_C'),
(5636, 'registration coordinator', 'MARKS_SETUP_R'),
(5637, 'registration coordinator', 'MARKS_SETUP_U'),
(5638, 'registration coordinator', 'MARKS_SETUP_D'),
(5639, 'registration coordinator', 'PERMISSION_C'),
(5640, 'registration coordinator', 'PERMISSION_R'),
(5641, 'registration coordinator', 'PERMISSION_U'),
(5642, 'registration coordinator', 'PERMISSION_D'),
(5643, 'registration coordinator', 'POSITION_C'),
(5644, 'registration coordinator', 'POSITION_R'),
(5645, 'registration coordinator', 'POSITION_U'),
(5646, 'registration coordinator', 'POSITION_D'),
(5647, 'registration coordinator', 'PROJECT_C'),
(5648, 'registration coordinator', 'PROJECT_R'),
(5649, 'registration coordinator', 'PROJECT_U'),
(5650, 'registration coordinator', 'PROJECT_D'),
(5651, 'registration coordinator', 'QUESTION_C'),
(5652, 'registration coordinator', 'QUESTION_R'),
(5653, 'registration coordinator', 'QUESTION_U'),
(5654, 'registration coordinator', 'QUESTION_D'),
(5655, 'registration coordinator', 'REGISTRATION_C'),
(5656, 'registration coordinator', 'REGISTRATION_R'),
(5657, 'registration coordinator', 'REGISTRATION_U'),
(5658, 'registration coordinator', 'REGISTRATION_D'),
(5659, 'registration coordinator', 'RESULT_C'),
(5660, 'registration coordinator', 'RESULT_R'),
(5661, 'registration coordinator', 'RESULT_U'),
(5662, 'registration coordinator', 'RESULT_D'),
(5663, 'registration coordinator', 'ROLE_C'),
(5664, 'registration coordinator', 'ROLE_R'),
(5665, 'registration coordinator', 'ROLE_U'),
(5666, 'registration coordinator', 'ROLE_D'),
(5667, 'registration coordinator', 'SCHOOL_C'),
(5668, 'registration coordinator', 'SCHOOL_R'),
(5669, 'registration coordinator', 'SCHOOL_U'),
(5670, 'registration coordinator', 'SCHOOL_D'),
(5671, 'registration coordinator', 'SESSION_C'),
(5672, 'registration coordinator', 'SESSION_R'),
(5673, 'registration coordinator', 'SESSION_U'),
(5674, 'registration coordinator', 'SESSION_D'),
(5675, 'registration coordinator', 'SURVEY_C'),
(5676, 'registration coordinator', 'SURVEY_R'),
(5677, 'registration coordinator', 'SURVEY_U'),
(5678, 'registration coordinator', 'SURVEY_D'),
(5679, 'registration coordinator', 'SURVEY_QUESTION_C'),
(5680, 'registration coordinator', 'SURVEY_QUESTION_R'),
(5681, 'registration coordinator', 'SURVEY_QUESTION_U'),
(5682, 'registration coordinator', 'SURVEY_QUESTION_D'),
(5683, 'registration coordinator', 'SURVEY_QUESTION_FILLUP_C'),
(5684, 'registration coordinator', 'SURVEY_QUESTION_FILLUP_R'),
(5685, 'registration coordinator', 'SURVEY_QUESTION_FILLUP_U'),
(5686, 'registration coordinator', 'SURVEY_QUESTION_FILLUP_D'),
(5687, 'registration coordinator', 'SURVEY_QUESTION_TYPE_C'),
(5688, 'registration coordinator', 'SURVEY_QUESTION_TYPE_R'),
(5689, 'registration coordinator', 'SURVEY_QUESTION_TYPE_U'),
(5690, 'registration coordinator', 'SURVEY_QUESTION_TYPE_D'),
(5691, 'registration coordinator', 'TASK_C'),
(5692, 'registration coordinator', 'TASK_R'),
(5693, 'registration coordinator', 'TASK_U'),
(5694, 'registration coordinator', 'TASK_D'),
(5695, 'registration coordinator', 'TASK_CATEGORY_C'),
(5696, 'registration coordinator', 'TASK_CATEGORY_R'),
(5697, 'registration coordinator', 'TASK_CATEGORY_U'),
(5698, 'registration coordinator', 'TASK_CATEGORY_D'),
(5699, 'registration coordinator', 'TERM_C'),
(5700, 'registration coordinator', 'TERM_R'),
(5701, 'registration coordinator', 'TERM_U'),
(5702, 'registration coordinator', 'TERM_D'),
(5703, 'registration coordinator', 'THESIS_C'),
(5704, 'registration coordinator', 'THESIS_R'),
(5705, 'registration coordinator', 'THESIS_U'),
(5706, 'registration coordinator', 'THESIS_D'),
(5707, 'registration coordinator', 'USER_C'),
(5708, 'registration coordinator', 'USER_R'),
(5709, 'registration coordinator', 'USER_U'),
(5710, 'registration coordinator', 'USER_D'),
(5711, 'registration coordinator', 'VIDEO_C'),
(5712, 'registration coordinator', 'VIDEO_R'),
(5713, 'registration coordinator', 'VIDEO_U'),
(5714, 'registration coordinator', 'VIDEO_D'),
(5715, 'registration coordinator', 'VIDEO_COMMENT_C'),
(5716, 'registration coordinator', 'VIDEO_COMMENT_R'),
(5717, 'registration coordinator', 'VIDEO_COMMENT_U'),
(5718, 'registration coordinator', 'VIDEO_COMMENT_D'),
(5719, 'registration coordinator', 'YEAR_C'),
(5720, 'registration coordinator', 'YEAR_R'),
(5721, 'registration coordinator', 'YEAR_U'),
(5722, 'registration coordinator', 'YEAR_D'),
(5773, 'stuff', 'BLOOD_C'),
(5774, 'stuff', 'BLOOD_R'),
(5775, 'stuff', 'BLOOD_U'),
(5776, 'stuff', 'CALENDAR_R'),
(5777, 'tabulator', 'BLOOD_C'),
(5778, 'tabulator', 'BLOOD_R'),
(5779, 'tabulator', 'BLOOD_U'),
(5780, 'tabulator', 'CALENDAR_R'),
(6400, 'teacher', 'BLOOD_C'),
(6401, 'teacher', 'BLOOD_R'),
(6402, 'teacher', 'BLOOD_U'),
(6403, 'teacher', 'CALENDAR_R'),
(6404, 'teacher', 'COURSE_C'),
(6405, 'teacher', 'COURSE_R'),
(6406, 'teacher', 'COURSE_U'),
(6407, 'teacher', 'COURSE_D'),
(6408, 'teacher', 'DISCUSSION_C'),
(6409, 'teacher', 'DISCUSSION_R'),
(6410, 'teacher', 'DISCUSSION_U'),
(6411, 'teacher', 'DISCUSSION_D'),
(6412, 'teacher', 'DISCUSSION_CAT_C'),
(6413, 'teacher', 'DISCUSSION_CAT_R'),
(6414, 'teacher', 'DISCUSSION_CAT_U'),
(6415, 'teacher', 'DISCUSSION_CAT_D'),
(6416, 'teacher', 'DISCUSSION_COMMENT_C'),
(6417, 'teacher', 'DISCUSSION_COMMENT_R'),
(6418, 'teacher', 'DISCUSSION_COMMENT_U'),
(6419, 'teacher', 'DISCUSSION_COMMENT_D'),
(6420, 'teacher', 'FILE_C'),
(6421, 'teacher', 'FILE_R'),
(6422, 'teacher', 'FILE_U'),
(6423, 'teacher', 'FILE_D'),
(6424, 'teacher', 'PROJECT_C'),
(6425, 'teacher', 'PROJECT_R'),
(6426, 'teacher', 'PROJECT_U'),
(6427, 'teacher', 'PROJECT_D'),
(6428, 'teacher', 'QUESTION_C'),
(6429, 'teacher', 'QUESTION_R'),
(6430, 'teacher', 'QUESTION_U'),
(6431, 'teacher', 'QUESTION_D'),
(6432, 'teacher', 'REGISTRATION_C'),
(6433, 'teacher', 'REGISTRATION_R'),
(6434, 'teacher', 'REGISTRATION_U'),
(6435, 'teacher', 'REGISTRATION_D'),
(6436, 'teacher', 'RESULT_C'),
(6437, 'teacher', 'RESULT_R'),
(6438, 'teacher', 'RESULT_U'),
(6439, 'teacher', 'RESULT_D'),
(6440, 'teacher', 'VIDEO_C'),
(6441, 'teacher', 'VIDEO_R'),
(6442, 'teacher', 'VIDEO_U'),
(6443, 'teacher', 'VIDEO_D'),
(6444, 'teacher', 'VIDEO_COMMENT_C'),
(6445, 'teacher', 'VIDEO_COMMENT_R'),
(6446, 'teacher', 'VIDEO_COMMENT_U'),
(6447, 'teacher', 'VIDEO_COMMENT_D'),
(6448, 'student', 'CLUB_C'),
(6449, 'student', 'CLUB_R'),
(6450, 'student', 'CLUB_U'),
(6451, 'student', 'CLUB_D'),
(6452, 'student', 'DISCUSSION_C'),
(6453, 'student', 'DISCUSSION_R'),
(6454, 'student', 'DISCUSSION_U'),
(6455, 'student', 'DISCUSSION_D'),
(6456, 'student', 'DISCUSSION_COMMENT_C'),
(6457, 'student', 'DISCUSSION_COMMENT_R'),
(6458, 'student', 'DISCUSSION_COMMENT_U'),
(6459, 'student', 'DISCUSSION_COMMENT_D'),
(6460, 'student', 'FILE_C'),
(6461, 'student', 'FILE_R'),
(6462, 'student', 'FILE_U'),
(6463, 'student', 'FILE_D'),
(6464, 'student', 'JOB_R'),
(6465, 'student', 'PROJECT_C'),
(6466, 'student', 'PROJECT_R'),
(6467, 'student', 'PROJECT_U'),
(6468, 'student', 'PROJECT_D'),
(6469, 'student', 'QUESTION_C'),
(6470, 'student', 'QUESTION_R'),
(6471, 'student', 'QUESTION_U'),
(6472, 'student', 'QUESTION_D'),
(6473, 'student', 'REGISTRATION_R'),
(6474, 'student', 'RESULT_R'),
(6475, 'student', 'USER_R'),
(6476, 'student', 'VIDEO_C'),
(6477, 'student', 'VIDEO_R'),
(6478, 'student', 'VIDEO_U'),
(6479, 'student', 'VIDEO_D'),
(6480, 'student', 'VIDEO_COMMENT_C'),
(6481, 'student', 'VIDEO_COMMENT_R'),
(6482, 'student', 'VIDEO_COMMENT_U'),
(6483, 'student', 'VIDEO_COMMENT_D'),
(6484, 'administrator', 'ASSET_C'),
(6485, 'administrator', 'ASSET_R'),
(6486, 'administrator', 'ASSET_U'),
(6487, 'administrator', 'ASSET_D'),
(6488, 'administrator', 'ATTENDANCE_C'),
(6489, 'administrator', 'ATTENDANCE_R'),
(6490, 'administrator', 'ATTENDANCE_U'),
(6491, 'administrator', 'ATTENDANCE_D'),
(6492, 'administrator', 'BLOOD_C'),
(6493, 'administrator', 'BLOOD_R'),
(6494, 'administrator', 'BLOOD_U'),
(6495, 'administrator', 'BLOOD_D'),
(6496, 'administrator', 'BOOK_C'),
(6497, 'administrator', 'BOOK_R'),
(6498, 'administrator', 'BOOK_U'),
(6499, 'administrator', 'BOOK_D'),
(6500, 'administrator', 'BUDGET'),
(6501, 'administrator', 'BUDGET_R'),
(6502, 'administrator', 'BUDGET_U'),
(6503, 'administrator', 'BUDGET_D'),
(6504, 'administrator', 'CALENDAR_C'),
(6505, 'administrator', 'CALENDAR_R'),
(6506, 'administrator', 'CALENDAR_U'),
(6507, 'administrator', 'CALENDAR_D'),
(6508, 'administrator', 'CCA_C'),
(6509, 'administrator', 'CCA_R'),
(6510, 'administrator', 'CCA_U'),
(6511, 'administrator', 'CCA_D'),
(6512, 'administrator', 'CLUB_C'),
(6513, 'administrator', 'CLUB_R'),
(6514, 'administrator', 'CLUB_U'),
(6515, 'administrator', 'CLUB_D'),
(6516, 'administrator', 'COURSE_C'),
(6517, 'administrator', 'COURSE_R'),
(6518, 'administrator', 'COURSE_U'),
(6519, 'administrator', 'COURSE_D'),
(6520, 'administrator', 'COURSE_SESSIONAL_TYPE_C'),
(6521, 'administrator', 'COURSE_SESSIONAL_TYPE_R'),
(6522, 'administrator', 'COURSE_SESSIONAL_TYPE_U'),
(6523, 'administrator', 'COURSE_SESSIONAL_TYPE_D'),
(6524, 'administrator', 'COURSE_TYPE_C'),
(6525, 'administrator', 'COURSE_TYPE_R'),
(6526, 'administrator', 'COURSE_TYPE_U'),
(6527, 'administrator', 'COURSE_TYPE_D'),
(6528, 'administrator', 'DISCIPLINE_C'),
(6529, 'administrator', 'DISCIPLINE_R'),
(6530, 'administrator', 'DISCIPLINE_U'),
(6531, 'administrator', 'DISCIPLINE_D'),
(6532, 'administrator', 'DISCUSSION_C'),
(6533, 'administrator', 'DISCUSSION_R'),
(6534, 'administrator', 'DISCUSSION_U'),
(6535, 'administrator', 'DISCUSSION_D'),
(6536, 'administrator', 'DISCUSSION_CAT_C'),
(6537, 'administrator', 'DISCUSSION_CAT_R'),
(6538, 'administrator', 'DISCUSSION_CAT_U'),
(6539, 'administrator', 'DISCUSSION_CAT_D'),
(6540, 'administrator', 'DISCUSSION_COMMENT_C'),
(6541, 'administrator', 'DISCUSSION_COMMENT_R'),
(6542, 'administrator', 'DISCUSSION_COMMENT_U'),
(6543, 'administrator', 'DISCUSSION_COMMENT_D'),
(6544, 'administrator', 'EMAIL_C'),
(6545, 'administrator', 'EMAIL_R'),
(6546, 'administrator', 'EMAIL_U'),
(6547, 'administrator', 'EMAIL_D'),
(6548, 'administrator', 'FILE_C'),
(6549, 'administrator', 'FILE_R'),
(6550, 'administrator', 'FILE_U'),
(6551, 'administrator', 'FILE_D'),
(6552, 'administrator', 'GRADE_SETUP_C'),
(6553, 'administrator', 'GRADE_SETUP_R'),
(6554, 'administrator', 'GRADE_SETUP_U'),
(6555, 'administrator', 'GRADE_SETUP_D'),
(6556, 'administrator', 'JOB_C'),
(6557, 'administrator', 'JOB_R'),
(6558, 'administrator', 'JOB_U'),
(6559, 'administrator', 'JOB_D'),
(6560, 'administrator', 'JOB_C'),
(6561, 'administrator', 'JOB_R'),
(6562, 'administrator', 'JOB_U'),
(6563, 'administrator', 'JOB_D'),
(6564, 'administrator', 'MARKS_SETUP_C'),
(6565, 'administrator', 'MARKS_SETUP_R'),
(6566, 'administrator', 'MARKS_SETUP_U'),
(6567, 'administrator', 'MARKS_SETUP_D'),
(6568, 'administrator', 'PAYMENT_U'),
(6569, 'administrator', 'PAYMENT_D'),
(6570, 'administrator', 'PAYMENT_LOG_U'),
(6571, 'administrator', 'PAYMENT_LOG_D'),
(6572, 'administrator', 'PAYMENT_RECHARGE_U'),
(6573, 'administrator', 'PAYMENT_RECHARGE_D'),
(6574, 'administrator', 'PERMISSION_C'),
(6575, 'administrator', 'PERMISSION_R'),
(6576, 'administrator', 'PERMISSION_U'),
(6577, 'administrator', 'PERMISSION_D'),
(6578, 'administrator', 'POSITION_C'),
(6579, 'administrator', 'POSITION_R'),
(6580, 'administrator', 'POSITION_U'),
(6581, 'administrator', 'POSITION_D'),
(6582, 'administrator', 'PRODUCT_U'),
(6583, 'administrator', 'PRODUCT_D'),
(6584, 'administrator', 'PROJECT_C'),
(6585, 'administrator', 'PROJECT_R'),
(6586, 'administrator', 'PROJECT_U'),
(6587, 'administrator', 'PROJECT_D'),
(6588, 'administrator', 'QUESTION_C'),
(6589, 'administrator', 'QUESTION_R'),
(6590, 'administrator', 'QUESTION_U'),
(6591, 'administrator', 'QUESTION_D'),
(6592, 'administrator', 'REGISTRATION_C'),
(6593, 'administrator', 'REGISTRATION_R'),
(6594, 'administrator', 'REGISTRATION_U'),
(6595, 'administrator', 'REGISTRATION_D'),
(6596, 'administrator', 'RESULT_C'),
(6597, 'administrator', 'RESULT_R'),
(6598, 'administrator', 'RESULT_U'),
(6599, 'administrator', 'RESULT_D'),
(6600, 'administrator', 'ROLE_C'),
(6601, 'administrator', 'ROLE_R'),
(6602, 'administrator', 'ROLE_U'),
(6603, 'administrator', 'ROLE_D'),
(6604, 'administrator', 'SCHOLARSHIP_C'),
(6605, 'administrator', 'SCHOLARSHIP_R'),
(6606, 'administrator', 'SCHOLARSHIP_U'),
(6607, 'administrator', 'SCHOLARSHIP_D'),
(6608, 'administrator', 'SCHOLARSHIP_APPLIED_C'),
(6609, 'administrator', 'SCHOLARSHIP_APPLIED_R'),
(6610, 'administrator', 'SCHOLARSHIP_APPLIED_U'),
(6611, 'administrator', 'SCHOLARSHIP_APPLIED_D'),
(6612, 'administrator', 'SCHOLARSHIP_CV_C'),
(6613, 'administrator', 'SCHOLARSHIP_CV_R'),
(6614, 'administrator', 'SCHOLARSHIP_CV_U'),
(6615, 'administrator', 'SCHOLARSHIP_CV_D'),
(6616, 'administrator', 'SCHOLARSHIP_TYPE_C'),
(6617, 'administrator', 'SCHOLARSHIP_TYPE_R'),
(6618, 'administrator', 'SCHOLARSHIP_TYPE_U'),
(6619, 'administrator', 'SCHOLARSHIP_TYPE_D'),
(6620, 'administrator', 'SCHOOL_C'),
(6621, 'administrator', 'SCHOOL_R'),
(6622, 'administrator', 'SCHOOL_U'),
(6623, 'administrator', 'SCHOOL_D'),
(6624, 'administrator', 'SESSION_C'),
(6625, 'administrator', 'SESSION_R'),
(6626, 'administrator', 'SESSION_U'),
(6627, 'administrator', 'SESSION_D'),
(6628, 'administrator', 'SURVEY_C'),
(6629, 'administrator', 'SURVEY_R'),
(6630, 'administrator', 'SURVEY_U'),
(6631, 'administrator', 'SURVEY_D'),
(6632, 'administrator', 'SURVEY_QUESTION_C'),
(6633, 'administrator', 'SURVEY_QUESTION_R'),
(6634, 'administrator', 'SURVEY_QUESTION_U'),
(6635, 'administrator', 'SURVEY_QUESTION_D'),
(6636, 'administrator', 'SURVEY_QUESTION_FILLUP_C'),
(6637, 'administrator', 'SURVEY_QUESTION_FILLUP_R'),
(6638, 'administrator', 'SURVEY_QUESTION_FILLUP_U'),
(6639, 'administrator', 'SURVEY_QUESTION_FILLUP_D'),
(6640, 'administrator', 'SURVEY_QUESTION_TYPE_C'),
(6641, 'administrator', 'SURVEY_QUESTION_TYPE_R'),
(6642, 'administrator', 'SURVEY_QUESTION_TYPE_U'),
(6643, 'administrator', 'SURVEY_QUESTION_TYPE_D'),
(6644, 'administrator', 'TASK_C'),
(6645, 'administrator', 'TASK_R'),
(6646, 'administrator', 'TASK_U'),
(6647, 'administrator', 'TASK_D'),
(6648, 'administrator', 'TASK_CATEGORY_C'),
(6649, 'administrator', 'TASK_CATEGORY_R'),
(6650, 'administrator', 'TASK_CATEGORY_U'),
(6651, 'administrator', 'TASK_CATEGORY_D'),
(6652, 'administrator', 'TERM_C'),
(6653, 'administrator', 'TERM_R'),
(6654, 'administrator', 'TERM_U'),
(6655, 'administrator', 'TERM_D'),
(6656, 'administrator', 'THESIS_C'),
(6657, 'administrator', 'THESIS_R'),
(6658, 'administrator', 'THESIS_U'),
(6659, 'administrator', 'THESIS_D'),
(6660, 'administrator', 'USER_C'),
(6661, 'administrator', 'USER_R'),
(6662, 'administrator', 'USER_U'),
(6663, 'administrator', 'USER_D'),
(6664, 'administrator', 'VIDEO_C'),
(6665, 'administrator', 'VIDEO_R'),
(6666, 'administrator', 'VIDEO_U'),
(6667, 'administrator', 'VIDEO_D'),
(6668, 'administrator', 'VIDEO_COMMENT_C'),
(6669, 'administrator', 'VIDEO_COMMENT_R'),
(6670, 'administrator', 'VIDEO_COMMENT_U'),
(6671, 'administrator', 'VIDEO_COMMENT_D'),
(6672, 'administrator', 'YEAR_C'),
(6673, 'administrator', 'YEAR_R'),
(6674, 'administrator', 'YEAR_U'),
(6675, 'administrator', 'YEAR_D');

-- --------------------------------------------------------

--
-- Table structure for table `ums_school`
--

DROP TABLE IF EXISTS `ums_school`;
CREATE TABLE IF NOT EXISTS `ums_school` (
  `ID` varchar(40) NOT NULL,
  `Name` varchar(50) NOT NULL,
  `DeanID` varchar(40) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `ums_school`
--

INSERT INTO `ums_school` (`ID`, `Name`, `DeanID`) VALUES
('{39DDC0C2-CFC2-4246-8748-8812B1751A5C}', 'Science Engineering and Technology', ''),
('{4D46079B-AFA3-40F1-B8D1-6CC9E9F56812}', 'Life Science', ''),
('{86E0F021-B30D-48D2-B177-247180633C5E}', 'Social Science', ''),
('{879375F7-0A15-4705-AC90-C6786D279EF1}', 'Law and Humanities', ''),
('{CE09AA38-205B-4F50-A0E0-14DB8686C912}', 'Fine Arts', '');

-- --------------------------------------------------------

--
-- Table structure for table `ums_user`
--

DROP TABLE IF EXISTS `ums_user`;
CREATE TABLE IF NOT EXISTS `ums_user` (
  `ID` varchar(40) NOT NULL,
  `UniversityID` varchar(20) NOT NULL,
  `Email` varchar(50) NOT NULL,
  `Password` varchar(255) NOT NULL,
  `FirstName` varchar(50) DEFAULT NULL,
  `MiddleName` varchar(50) DEFAULT NULL,
  `LastName` varchar(50) DEFAULT NULL,
  `DisciplineID` varchar(40) DEFAULT NULL,
  `Status` varchar(20) DEFAULT NULL,
  `IsLogged` varchar(10) DEFAULT NULL,
  `IsArchived` varchar(10) DEFAULT NULL,
  `IsDeleted` varchar(10) DEFAULT NULL,
  PRIMARY KEY (`ID`),
  UNIQUE KEY `Email` (`Email`),
  UNIQUE KEY `UniversityID` (`UniversityID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `ums_user`
--

INSERT INTO `ums_user` (`ID`, `UniversityID`, `Email`, `Password`, `FirstName`, `MiddleName`, `LastName`, `DisciplineID`, `Status`, `IsLogged`, `IsArchived`, `IsDeleted`) VALUES
('avi@gmail.com', '160211', 'avi@gmail.com', '$2y$10$7KR9kj/ePlAQjVPTdSIvCOxnqSTaWDxJAcNEHQDbzuF1Pxv.wDD/G', 'avi', 'dev', 'raha', '{FFDB1CB8-AF34-4381-8971-9784DCB516C5}', 'approved', NULL, NULL, NULL),
('lotif@gmail.com', '160212', 'lotif@gmail.com', '$2y$10$MBB/ST/yOmtXog3FSEzneevL07erAGyxWK/pX/KT7QVSysSVqRaHq', 'Abdul', 'Lotif', 'Limon', '{FFDB1CB8-AF34-4381-8971-9784DCB516C5}', 'approved', NULL, NULL, NULL),
('mefahimrahman@gmail.com', '160215', 'mefahimrahman@gmail.com', '$2y$10$QbW2GR7NKoATFXY6E2oLSeVmR3IPr3C1zrKkJikSQAejK39V1eW2m', 'Fahim', '', 'Rahman', '{FFDB1CB8-AF34-4381-8971-9784DCB516C5}', 'approved', NULL, NULL, NULL),
('mkazi078@uottawa.ca', '020229', 'mkazi078@uottawa.ca', '$2y$10$l0gFzILMq03DcwcBGxIdgunnOd9G5kF8J8ucZZvCKkt8mNGlI74/W', 'Kazi', 'Masudul', 'Alam', '{FFDB1CB8-AF34-4381-8971-9784DCB516C5}', 'approved', NULL, NULL, NULL),
('monir1527@cseku.ac.bd', '150227', 'monir1527@cseku.ac.bd', '$2y$10$bxiwmwOXM/VTMFK7lhc8juaFCzzZjSymqf.8QCJYyLv9UUPs0xEPy', 'Md', 'Moniruzzaman', 'Aurangzeb', '{FFDB1CB8-AF34-4381-8971-9784DCB516C5}', 'approved', NULL, NULL, NULL),
('rokeya@gmail.com', '160210', 'rokeya@gmail.com', '$2y$10$4VNGxyf8mttFjuy2E07VkuZ3E4N4m09xugiq1hofd2vVty0ZXE9L.', 'Rokeya', '', 'sadaf', '{FFDB1CB8-AF34-4381-8971-9784DCB516C5}', 'approved', NULL, NULL, NULL),
('ryhan1630@cseku.ac.bd', '160230', 'ryhan1630@cseku.ac.bd', '$2y$10$4VNGxyf8mttFjuy2E07VkuZ3E4N4m09xugiq1hofd2vVty0ZXE9L.', 'Ryhan', 'Ahmed', 'Tamim', '{FFDB1CB8-AF34-4381-8971-9784DCB516C5}', 'approved', NULL, NULL, NULL),
('saimumislam96@gmail.com', '160227', 'saimumislam96@gmail.com', '$2y$10$BjexPvEbArRS7lcxvjHQ0.xegDY83Twv6REeuZ2B11IQ6Xr5qaV5G', 'saimum', '', 'islam', '{FFDB1CB8-AF34-4381-8971-9784DCB516C5}', 'approved', NULL, NULL, NULL);

-- --------------------------------------------------------

--
-- Table structure for table `ums_user_details`
--

DROP TABLE IF EXISTS `ums_user_details`;
CREATE TABLE IF NOT EXISTS `ums_user_details` (
  `ID` varchar(40) NOT NULL,
  `FatherName` varchar(100) DEFAULT NULL,
  `MotherName` varchar(100) DEFAULT NULL,
  `PermanentAddress` varchar(200) DEFAULT NULL,
  `HomePhone` varchar(20) DEFAULT NULL,
  `CurrentAddress` varchar(200) DEFAULT NULL,
  `MobilePhone` varchar(20) DEFAULT NULL,
  `blood_group` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `ums_user_details`
--

INSERT INTO `ums_user_details` (`ID`, `FatherName`, `MotherName`, `PermanentAddress`, `HomePhone`, `CurrentAddress`, `MobilePhone`, `blood_group`) VALUES
('avi@gmail.com', NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('lotif@gmail.com', NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('mefahimrahman@gmail.com', NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('mkazi078@uottawa.ca', 'Kazi Shahidul Alam', 'Hosneara Jahan', '49/2, Rokon Uddin Sarak, East Baniakhamar, Khulna', '0417223344', 'Same', '01711149360 ', 'O+'),
('monir1527@cseku.ac.bd', NULL, NULL, NULL, NULL, NULL, NULL, 'O+'),
('rokeya@gmail.com', NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('ryhan1630@cseku.ac.bd', NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('saimumislam96@gmail.com', 'Rafiqul Islam', 'Shahida khatun', 'khulna', '01763706245', 'ku', '01763706245 ', NULL);

-- --------------------------------------------------------

--
-- Table structure for table `ums_user_discipline`
--

DROP TABLE IF EXISTS `ums_user_discipline`;
CREATE TABLE IF NOT EXISTS `ums_user_discipline` (
  `UserID` varchar(40) NOT NULL,
  `DisciplineID` varchar(40) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `ums_user_position`
--

DROP TABLE IF EXISTS `ums_user_position`;
CREATE TABLE IF NOT EXISTS `ums_user_position` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `UserID` varchar(40) NOT NULL,
  `PositionID` varchar(40) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=56 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `ums_user_position`
--

INSERT INTO `ums_user_position` (`ID`, `UserID`, `PositionID`) VALUES
(50, 'aysha@gmail.com', '{7CDA1F32-A2F8-4469-B5A8-C2038FCE1F9A}'),
(55, 'mkazi078@uottawa.ca', '{C27B6BCF-FB83-4F3D-85CA-B7870D8B12D0}');

-- --------------------------------------------------------

--
-- Table structure for table `ums_user_role`
--

DROP TABLE IF EXISTS `ums_user_role`;
CREATE TABLE IF NOT EXISTS `ums_user_role` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `UserID` varchar(40) NOT NULL,
  `RoleID` varchar(40) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=185 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `ums_user_role`
--

INSERT INTO `ums_user_role` (`ID`, `UserID`, `RoleID`) VALUES
(122, 'middle@test.com', 'student'),
(123, 'middle@test.com', 'student'),
(124, 'middle@test.com', 'student'),
(125, 'middle@test.com', 'student'),
(126, 'middle@test.com', 'student'),
(127, 'middle@test.com', 'student'),
(128, 'middle@test.com', 'student'),
(129, 'middle@test.com', 'student'),
(130, 'middle@test.com', 'student'),
(131, 'middle@test.com', 'student'),
(132, 'middle@test.com', 'student'),
(133, 'middle@test.com', 'student'),
(134, 'middle@test.com', 'student'),
(135, 'middle@test.com', 'student'),
(136, 'middle@test.com', 'student'),
(137, 'middle@test.com', 'student'),
(138, 'middle@test.com', 'student'),
(144, 'middle1@test.com', 'student'),
(168, 'saimumislam96@gmail.com', 'administrator'),
(172, 'avi@gmail.com', 'teacher'),
(173, 'lotif@gmail.com', 'student'),
(174, 'rokeya@gmail.com', 'student'),
(175, 'ryhan1630@cseku.ac.bd', 'administrator'),
(181, 'mkazi078@uottawa.ca', 'administrator'),
(182, 'mkazi078@uottawa.ca', 'teacher'),
(183, 'monir1527@cseku.ac.bd', 'student'),
(184, 'mefahimrahman@gmail.com', 'administrator');

-- --------------------------------------------------------

--
-- Table structure for table `vtms_video`
--

DROP TABLE IF EXISTS `vtms_video`;
CREATE TABLE IF NOT EXISTS `vtms_video` (
  `ID` varchar(40) NOT NULL,
  `Title` varchar(1500) NOT NULL,
  `Description` varchar(1500) NOT NULL,
  `TagID` varchar(40) NOT NULL,
  `Link` varchar(150) NOT NULL,
  `IsEmbed` tinyint(1) NOT NULL,
  `CreationDate` datetime DEFAULT NULL,
  `CreatorID` varchar(40) NOT NULL,
  `Views` int(10) NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `vtms_video`
--

INSERT INTO `vtms_video` (`ID`, `Title`, `Description`, `TagID`, `Link`, `IsEmbed`, `CreationDate`, `CreatorID`, `Views`) VALUES
('{27438FB4-1128-4F81-B55A-2A7AF4EC669C}', 'How to learn coding language or programming language easily.', 'Hey whats up guys in today\'s video I\'ll show you that how can you learn coding language o', 'programmig', 'https://www.youtube.com/watch?v=VZzaqgxyHJs', 0, '2019-04-11 13:26:46', 'mkazi078@uottawa.ca', 0);

-- --------------------------------------------------------

--
-- Table structure for table `vtms_video_comment`
--

DROP TABLE IF EXISTS `vtms_video_comment`;
CREATE TABLE IF NOT EXISTS `vtms_video_comment` (
  `CommentID` varchar(40) NOT NULL,
  `Comment` varchar(1500) NOT NULL,
  `CreatorID` varchar(40) NOT NULL,
  `VideoID` varchar(40) NOT NULL,
  `CommentIDTop` varchar(40) DEFAULT NULL,
  `CreationDate` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `vtms_video_comment`
--

INSERT INTO `vtms_video_comment` (`CommentID`, `Comment`, `CreatorID`, `VideoID`, `CommentIDTop`, `CreationDate`) VALUES
('{138A18E4-CBBD-4E61-9C22-76353363B917}', 'dfd', 'mkazi078@uottawa.ca', '{27438FB4-1128-4F81-B55A-2A7AF4EC669C}', '0', '2019-04-11 13:27:01'),
('{C7D8F7AE-B5C2-4342-892C-E9F5EA249214}', 'ghjgj', 'mkazi078@uottawa.ca', '{27438FB4-1128-4F81-B55A-2A7AF4EC669C}', '{138A18E4-CBBD-4E61-9C22-76353363B917}', '2019-04-11 13:27:07');

-- --------------------------------------------------------

--
-- Table structure for table `vtms_video_tag`
--

DROP TABLE IF EXISTS `vtms_video_tag`;
CREATE TABLE IF NOT EXISTS `vtms_video_tag` (
  `VideoID` varchar(40) NOT NULL,
  `Tag` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `tms_link_thesis`
--
ALTER TABLE `tms_link_thesis`
  ADD CONSTRAINT `tms_link_thesis_ibfk_1` FOREIGN KEY (`thesis_id`) REFERENCES `tms_thesis` (`id`) ON DELETE CASCADE ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
