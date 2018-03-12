
#include "Speaker.hpp"

Speaker* Speaker::m_speaker = nullptr;

Speaker* Speaker::getInstance()
{
	if(m_speaker == nullptr)
	{
		m_speaker = new Speaker;
	}

	return m_speaker;
}

void Speaker::tuneMusic(Music* music)
{
	music->Sound();
}
