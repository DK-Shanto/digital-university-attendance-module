<?php
//session_start();
include_once 'blade/view.videosearch.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.video.inc';
include_once 'blade/view.video.blade.inc';


?>
<div class="panel panel-default">
    
    <div class="panel-heading">Video Search</div>
    
    <div class="panel-body">

	
	<div id="form" >



<form method = "post"class="form-inline mr-auto">
  <input class="form-control mr-sm-2" name ="txtsearch" type="text" placeholder="Search" aria-label="Search">
  <button class="btn btn-outline-success btn-rounded btn-sm my-0" type="submit" id="savebutton" name="search" value="search">Search</button>
</form>

	</div>
	</div>

	<div class="panel-body">			
	<table class="table table-striped">
	<tr>
		<th>Video Title</th>
	</tr>	
	<?php
	
	$tag = null;
				
	if(isset($_GET["tag"]))
	{
		$tag = $_GET["tag"];
	}

	
	$Result = $_VideoBAO->searchVideo($tag);

	//if DAO access is successful to load all the Terms then show them one by one
	if($Result->getIsSuccess()){

		$VideoList = $Result->getResultObject();

	?>
		<?php
		for($i = 0; $i < sizeof($VideoList); $i++) {
			$Video = $VideoList[$i];
			?>
		    <tr>
			    <td >
			    <a href="video_comment.php?view=<?php echo $Video->getID(); ?>" onclick="return ; " >
			    <?php 
			    		

			    		echo $Video->getTitle()."</br>"; 
			    	  	echo "Tag : ".$Video->getTag()."</br>"; 
			    	  
			    		echo "Creator Email : ".$Video->getCreatorID()."</br>"; 
		    		echo "Creator : ".$Video->getCreationDate()."</br>"; 	

			    		?>
			    	
			    </a>
			    </td>
			    
		    </tr>
	    <?php

		}

	}
	else{

		echo $Result->getResultObject(); //giving failure message
	}

	?>
	</table>


	</div>
</div>	
