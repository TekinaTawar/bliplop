package com.tekinatawar.bliplop

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.viewModels
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.material.Button
import androidx.compose.material.MaterialTheme
import androidx.compose.material.Surface
import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.tooling.preview.Preview
import com.tekinatawar.bliplop.ui.theme.BlipLopTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        val viewModel = BlipLopViewModel()

        super.onCreate(savedInstanceState)
        setContent {
            BlipLopTheme {
                // A surface container using the 'background' color from the theme
                Surface(
                    modifier = Modifier.fillMaxSize(),
                    color = MaterialTheme.colors.background
                ) {
                    BlipLopApp(Modifier, viewModel)
                }
            }
        }
    }
}

@Composable
fun BlipLopApp(
    modifier: Modifier,
    viewModel: BlipLopViewModel
) {
    Column(
        modifier = modifier,
        horizontalAlignment = Alignment.CenterHorizontally,
        verticalArrangement = Arrangement.Center
    ) {
        // what is need of modifer in this button??
        Button(modifier = modifier, onClick = { viewModel.playBackClicked() }) {
            Text("Start Playback")
        }
    }

}